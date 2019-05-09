"""
Deployment fabfile for abl.is
"""
from __future__ import with_statement
from fabric.api import abort, cd, env, local, require, run, put, settings
from StringIO import StringIO
from os import path

# Module-specific configuration.
PROFILE_NAME = 'vkffz'
GIT_REPO = 'https://github.com/mikl/{name}.git'.format(name=PROFILE_NAME)
DEPLOY_PATH = '/srv/www/sites/vkffz.ch/builds'
SITE_PATH = DEPLOY_PATH + '/current'

DRUSH_MAKE_TEMPLATE = """
api = 2
core = 7.x
projects[drupal][version] = 7.67

projects[{profile}][type] = profile
projects[{profile}][download][type] = git
projects[{profile}][download][url] = {repo}
projects[{profile}][download][revision] = {tag}
"""

env.roledefs = {
    'production': ['imperator'],
}
env.user = 'fabric'

# Bash on FreeBSD.
env.shell = '/usr/local/bin/bash -l -c'

# Use the standard .ssh/config files.
env.use_ssh_config = True

# ================== SHARED CODE BELOW THIS LINE ================== #

def _build_make(buildpath, filepath, tag):
    # Generate a temporary make file, so we can run Drush make on it.
    _generate_makefile(filepath, tag)

    local('drush -y make --download-mechanism=curl {filepath} {destination}'.format(destination=buildpath, filepath=filepath))

    # Clean up the temporary make file once we're done with Drush make.
    local('rm {filepath}'.format(filepath=filepath))


def _clean_dist(buildpath):
    local('rm {buildpath}/.htaccess'.format(buildpath=buildpath))
    local('rm {buildpath}/*.txt'.format(buildpath=buildpath))
    local('rm {buildpath}/authorize.php'.format(buildpath=buildpath))
    local('rm {buildpath}/install.php'.format(buildpath=buildpath))
    local('rm -r {buildpath}/sites'.format(buildpath=buildpath))
    local('rm {buildpath}/web.config'.format(buildpath=buildpath))
    local('rm {buildpath}/xmlrpc.php'.format(buildpath=buildpath))

def _generate_makefile(filepath, tag):
    file_content = DRUSH_MAKE_TEMPLATE.format(profile=PROFILE_NAME, repo=GIT_REPO, tag=tag)

    makefile = open(filepath, 'w')
    makefile.write(file_content)
    makefile.close()


def _validate_version(version):
    """
    Helper function to validate that a proper version was given.
    """
    version = version.strip()

    return version


def _deploy_dirname(version):
    return version


def deploy(tag):
    """
    Deploy a tagged Git version to the server.

    Usage: "fab -R staging deploy:v1.0.0-beta.1".

    This command will make a new checkout of the profile repository, build
    the profile via its make file, replace the previous deployed version
    with the new build, and finally run the post deploy actions, upgrading
    the database, etc.
    """
    require('roles', used_for="configuring what servers to deploy to.")

    tag = tag.strip()

    if (len(tag) < 5):
        abort('Tag must be a valid tag name.')

    # Get a tempdir-name and create it.
    tempdir = local('mktemp -dt {profile}-deploy-XXXXXXXX'.format(profile=PROFILE_NAME), True)
    filepath = path.join(tempdir, 'build.make')
    buildpath = path.join(tempdir, _deploy_dirname(tag))

    _build_make(buildpath, filepath, tag)

    with cd(DEPLOY_PATH):
        # If our build folder already exists, remove it first.
        with settings(warn_only=True):
            run('rm -fr {tag}'.format(tag=tag))

        # Copy the build to the server.
        put(buildpath + '.tar.gz', DEPLOY_PATH)

        destination = path.join(DEPLOY_PATH, _deploy_dirname(tag))

        # Untar the new build.
        run('tar xzf {destination}.tar.gz -C {deploy}'.format(deploy=DEPLOY_PATH, destination=destination))

        # Remove the uploaded tarfile.
        run('rm {destination}.tar.gz'.format(destination=destination))

        # Symlink Drupal site folder down into our new build.
        run('ln -s ../../../site {tag}/sites/vkffz.ch'.format(tag=tag))
        run('ln -s ../../../site {tag}/sites/vkffz.mikl.ch'.format(tag=tag))

        # Remove the old "previous" symlink, rename the "current"
        # symlink to "previous".
        with settings(warn_only=True):
            run('rm previous')
            run('mv current previous')

        # Link the new release to "current"
        run('ln -s {tag} current'.format(tag=tag))

    post_deploy(tag)

    # Remove the temporary folder with the make file when we're done.
    local('rm -r {tempdir}'.format(tempdir=tempdir))


def dist(tag='', clean="no"):
    build_dir = path.relpath('build')
    filepath = path.join(build_dir, 'build.make')
    buildpath = path.join(build_dir, _deploy_dirname(tag))

    # Create the path hierarchy for the destination.
    local('mkdir -p {destination}'.format(destination=buildpath))

    # Then delete the target folder, since that'll be created by Drush make
    # automatically.
    local('rm -r {destination}'.format(destination=buildpath))

    _build_make(buildpath, filepath, tag)

    if (clean == 'yes'):
        _clean_dist(buildpath)


def post_deploy(tag=''):
    """
    Run post-deploy operations.

    This includes running database migrations, reverting features, emptying
    the cache and running cron to make sure your Drupal site is coherent.
    """

    # Clear the cache.
    run('drush -r {site} -l vkffz.ch -y cc all'.format(site=SITE_PATH))

    # Run database migrationsk
    run('drush -r {site} -l vkffz.ch -y updb'.format(site=SITE_PATH))

    # Run cron for good measure.
    run('drush -r {site} -l vkffz.ch -y cron'.format(site=SITE_PATH))


def tag_deploy(tag):
    """
    Tag and deploy a new release.
    """
    local('git push')
    local('git tag {tag}'.format(tag=tag))
    local('git push --tag')

    deploy(tag)


def tag_dist(tag, clean="no"):
    """
    Tag and deploy a new release.
    """
    local('git push')
    local('git tag {tag}'.format(tag=tag))
    local('git push --tag')

    dist(tag, clean)


def rollback():
    """
    Roll back to the previous version.
    """
    with cd(DEPLOY_PATH):
        # Remove the old "previous" symlink, rename the "current"
        # symlink to "previous".
        with settings(warn_only=True):
            run('rm current')
            run('mv previous current')

    post_deploy()
