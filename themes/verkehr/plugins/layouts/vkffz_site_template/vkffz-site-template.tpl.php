<?php
/**
 * @file
 * Site Template layout for Panels Everywhere.
 */
?>
<?php if ($content['header']): ?>
<header class="site-template-header" role="banner">
  <div class="section">
    <?php print render($content['header']); ?>
  </div>
</header>
<?php endif; ?>

<?php if ($content['subnav']): ?>
<header class="site-template-subnav" role="banner">
  <div class="section">
    <?php print render($content['subnav']); ?>
  </div>
</header>
<?php endif; ?>

<div class="site-template-main-wrap">
  <main class="site-template-main">
    <?php print render($content['content']); ?>
  </main>

  <aside class="site-template-sidebar">
    <?php print render($content['sidebar']); ?>
  </aside>
</div>


<?php if ($content['footer']): ?>
  <footer class="site-template-footer" role="contentinfo">
    <div class="section">
      <?php print render($content['footer']); ?>
    </div>
  </footer>
<?php endif; ?>

<?php print render($content['closure']); ?>
