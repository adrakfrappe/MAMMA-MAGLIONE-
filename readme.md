<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
<title>MAMMA MAGLIONE — README</title>
<link rel="preconnect" href="https://fonts.googleapis.com"/>
<link href="https://fonts.googleapis.com/css2?family=Geist+Mono:wght@300;400;500&display=swap" rel="stylesheet"/>
<style>
  *, *::before, *::after { box-sizing: border-box; margin: 0; padding: 0; }

  body {
    background: #ffffff;
    color: #1f2328;
    font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Helvetica, Arial, sans-serif;
    font-size: 16px;
    line-height: 1.6;
    max-width: 860px;
    margin: 0 auto;
    padding: 40px 24px 80px;
  }

  .repo-header { display: flex; align-items: center; gap: 10px; margin-bottom: 6px; }
  .repo-path { font-size: 20px; font-weight: 600; color: #0969da; }
  .repo-path span { color: #1f2328; }

  .badges { display: flex; flex-wrap: wrap; gap: 6px; margin: 14px 0 28px; }
  .badge {
    display: inline-flex; align-items: center; height: 20px;
    padding: 0 8px; font-size: 12px;
    font-family: 'Geist Mono', monospace;
    border-radius: 2em; font-weight: 500; white-space: nowrap;
  }
  .badge-blue   { background: #ddf4ff; color: #0969da; border: 1px solid #b6e3ff; }
  .badge-green  { background: #dafbe1; color: #1a7f37; border: 1px solid #aceebb; }
  .badge-orange { background: #fff1e5; color: #bc4c00; border: 1px solid #ffd8b5; }
  .badge-gray   { background: #f6f8fa; color: #57606a; border: 1px solid #d0d7de; }
  .badge-purple { background: #fbefff; color: #8250df; border: 1px solid #e2c5ff; }
  .badge-red    { background: #ffebe9; color: #cf222e; border: 1px solid #ffcecb; }

  hr { border: none; border-top: 1px solid #d0d7de; margin: 28px 0; }

  h1 { font-size: 30px; font-weight: 700; margin-bottom: 6px; padding-bottom: 10px; border-bottom: 1px solid #d0d7de; }
  .tagline { font-size: 15px; color: #57606a; margin-bottom: 20px; font-style: italic; }
  h2 { font-size: 21px; font-weight: 600; margin: 36px 0 14px; padding-bottom: 7px; border-bottom: 1px solid #d0d7de; }
  h3 { font-size: 15px; font-weight: 600; margin: 22px 0 8px; }
  p { margin-bottom: 14px; }
  a { color: #0969da; text-decoration: none; }
  a:hover { text-decoration: underline; }

  .about-box {
    background: #f6f8fa; border: 1px solid #d0d7de;
    border-radius: 6px; padding: 16px 18px;
    margin-bottom: 24px; font-size: 15px; line-height: 1.65;
  }

  ul { padding-left: 22px; margin-bottom: 14px; }
  ul li { margin-bottom: 7px; font-size: 15px; }

  table { width: 100%; border-collapse: collapse; font-size: 14px; margin: 14px 0 20px; }
  thead tr { background: #f6f8fa; }
  th { font-weight: 600; text-align: left; padding: 9px 14px; border: 1px solid #d0d7de; font-size: 13px; color: #57606a; }
  td { padding: 9px 14px; border: 1px solid #d0d7de; vertical-align: top; font-size: 14px; }
  tr:nth-child(even) td { background: #f6f8fa; }

  code {
    background: #f6f8fa; border: 1px solid #d0d7de;
    border-radius: 4px; padding: 2px 6px;
    font-family: 'Geist Mono', monospace; font-size: 13px; color: #1f2328;
  }

  pre {
    background: #161b22; border: 1px solid #30363d;
    border-radius: 6px; padding: 16px 20px;
    overflow-x: auto; margin: 12px 0 18px;
    font-family: 'Geist Mono', monospace; font-size: 13px;
    line-height: 1.65; color: #e6edf3;
  }
  pre .c { color: #8b949e; font-style: italic; }
  pre .k { color: #79c0ff; }
  pre .s { color: #a5d6ff; }
  pre .v { color: #ffa657; }
  pre .g { color: #7ee787; }

  .note {
    background: #ddf4ff; border: 1px solid #b6e3ff;
    border-left: 4px solid #0969da; border-radius: 6px;
    padding: 11px 15px; font-size: 14px; margin: 12px 0;
  }
  .warn {
    background: #fff8c5; border: 1px solid #e3b341;
    border-left: 4px solid #d29922; border-radius: 6px;
    padding: 11px 15px; font-size: 14px; margin: 12px 0;
  }

  .toc { background: #f6f8fa; border: 1px solid #d0d7de; border-radius: 6px; padding: 14px 18px; margin-bottom: 28px; display: inline-block; }
  .toc-title { font-size: 12px; font-weight: 600; color: #57606a; text-transform: uppercase; letter-spacing: 0.05em; margin-bottom: 8px; }
  .toc ol { padding-left: 18px; margin: 0; }
  .toc ol li { font-size: 14px; margin-bottom: 3px; }

  /* team credits inline */
  .team-row { display: flex; gap: 8px; flex-wrap: wrap; margin-top: 6px; }
  .team-chip {
    font-family: 'Geist Mono', monospace; font-size: 12px;
    background: #f6f8fa; border: 1px solid #d0d7de;
    border-radius: 4px; padding: 4px 10px; color: #1f2328;
  }

  .footer-meta { font-size: 13px; color: #57606a; }

  /* ingredient grid */
  .ing-grid { display: grid; grid-template-columns: 1fr 1fr; gap: 2px; background: #d0d7de; border: 1px solid #d0d7de; border-radius: 6px; overflow: hidden; margin: 14px 0 20px; }
  .ing-cell { background: #fff; padding: 10px 14px; font-size: 14px; }
  .ing-cell strong { display: block; font-size: 12px; color: #57606a; margin-bottom: 4px; text-transform: uppercase; letter-spacing: 0.04em; font-family: 'Geist Mono', monospace; }
</style>
</head>
<body>

<!-- REPO HEADER -->
<div class="repo-header">
  <span style="font-size:20px">🍕</span>
  <span class="repo-path">adrakfrappe / <span>MAMMA-MAGLIONE</span></span>
</div>

<div class="badges">
  <span class="badge badge-blue">C++17</span>
  <span class="badge badge-orange">SFML 2.6.0</span>
  <span class="badge badge-green">OOP</span>
  <span class="badge badge-gray">Visual Studio 2022</span>
  <span class="badge badge-gray">Windows</span>
  <span class="badge badge-red">hot-pizza.normal.ttf</span>
  <span class="badge badge-purple">BGM: Mambo Italiano.ogg</span>
</div>

<hr/>

<!-- TITLE -->
<h1>🍕 MAMMA MAGLIONE</h1>
<p class="tagline">A pixel-art Italian restaurant sim — make pizzas, salads &amp; milkshakes — built from scratch in C++ with SFML 2.6.0</p>

<div class="about-box">
  <strong>MAMMA MAGLIONE</strong> is a drag-and-drop cooking game set in a pixel-art Italian restaurant. The player takes randomised customer orders and fulfils them across three stations: the <strong>Pizza Kitchen</strong>, the <strong>Salad Bar</strong>, and the <strong>Milkshake Bar</strong>. Written entirely in <strong>C++17</strong> using <strong>SFML 2.6.0</strong>, with a custom OOP architecture — no game engine involved. The window runs at <strong>800×800</strong> with looping <em>Mambo Italiano</em> as background music and the custom font <em>hot-pizza.normal.ttf</em> throughout the UI.
</div>

<!-- TOC -->
<div class="toc">
  <div class="toc-title">Table of Contents</div>
  <ol>
    <li><a href="#screens">Game Screens &amp; Flow</a></li>
    <li><a href="#pizza">🍕 Pizza Bar</a></li>
    <li><a href="#salad">🥗 Salad Bar</a></li>
    <li><a href="#milkshake">🥤 Milkshake Bar</a></li>
    <li><a href="#orders">Random Order System</a></li>
    <li><a href="#architecture">Project Architecture</a></li>
    <li><a href="#assets">Assets &amp; Resources</a></li>
    <li><a href="#controls">Controls</a></li>
    <li><a href="#build">How to Build &amp; Run</a></li>
    <li><a href="#team">Team</a></li>
  </ol>
</div>

<!-- SCREENS -->
<h2 id="screens">🖥️ Game Screens &amp; Flow</h2>

<p>The game is driven by a <code>gamestate</code> enum. Five states are managed by the <code>Game</code> class, each with its own background texture and set of active UI buttons:</p>

<table>
  <thead><tr><th>State</th><th>Screen</th><th>Background File</th></tr></thead>
  <tbody>
    <tr><td><code>HOMEPAGE</code></td><td>Pixel-art restaurant exterior with team name overlays</td><td><code>outside.png</code></td></tr>
    <tr><td><code>ORDER_SCREEN</code></td><td>Customer order ticket — shows the randomly generated order</td><td><code>order.png</code></td></tr>
    <tr><td><code>COOKING_SCREEN</code></td><td>Pizza kitchen — drag toppings onto the dough</td><td><code>cooking station.png</code></td></tr>
    <tr><td><code>OVEN_SCREEN</code></td><td>Oven view for baking the pizza</td><td><code>oven.jpeg</code></td></tr>
    <tr><td><code>SALADBAR_SCREEN</code></td><td>Salad bar — drag ingredients into the bowl</td><td><code>salad bar.png</code></td></tr>
    <tr><td><code>Milkshake_bar</code></td><td>Milkshake bar — drag fruits &amp; ice cream into blender</td><td><code>milkshakebar.jpeg</code></td></tr>
  </tbody>
</table>

<p>Navigation between screens is handled by five persistent top-bar buttons: <strong>Order</strong>, <strong>Kitchen</strong>, <strong>Oven</strong>, <strong>Salad bar</strong>, and <strong>milkshake</strong>. Switching screens clears all previously placed ingredients automatically via <code>pizza.clearSaladIngredients()</code>, <code>pizza.clearpizzaingredients()</code>, and <code>pizza.clearmilk()</code>.</p>

<!-- PIZZA -->
<h2 id="pizza">🍕 Pizza Bar (Kitchen Screen)</h2>

<p>The kitchen screen renders a pizza dough on a cooking-station background. The player drags toppings from ingredient bowls at the bottom of the screen and drops them onto the dough.</p>

<h3>How placement works</h3>
<p>When a topping is released, <code>Pizza::placeIngredient()</code> checks if the drop position is within a <strong>150px radius</strong> of the pizza centre (<code>345, 220</code>). If it is, the position is snapped to a cell in a <strong>13×13 grid</strong> (cell size = 800/13 ≈ 61px) and the ingredient sprite is stored in <code>placedIngredients</code>. If dropped outside the circle, it is rejected. After every drop, the ingredient respawns to its original bowl position via <code>respawn()</code>.</p>

<p>The underlying grid is a <strong>rows × cols matrix of <code>sf::CircleShape</code></strong> objects, generated by <code>Pizza::generateMatrix()</code>, used as invisible slot markers.</p>

<h3>Pizza toppings available</h3>
<div class="ing-grid">
  <div class="ing-cell"><strong>File</strong>cheese--.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(540, 540)</div>
  <div class="ing-cell"><strong>File</strong>sausage-.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(670, 550)</div>
  <div class="ing-cell"><strong>File</strong>mushroom-.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(160, 545)</div>
  <div class="ing-cell"><strong>File</strong>pep--.png (pepperoni)</div>
  <div class="ing-cell"><strong>Spawn position</strong>(420, 550)</div>
  <div class="ing-cell"><strong>File</strong>olive-.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(30, 550)</div>
  <div class="ing-cell"><strong>File</strong>onion--.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(270, 538)</div>
</div>

<p>All ingredient sprites are scaled to <strong>0.25× their original size</strong> on load (<code>sprite.setScale(0.25f, 0.25f)</code>) so they fit the bowl UI at the bottom of the screen.</p>

<!-- SALAD -->
<h2 id="salad">🥗 Salad Bar</h2>

<p>The salad bar screen shows a top-down bowl on the salad bar background. The player drags fresh ingredients into the bowl and can also add liquid dressings via dedicated buttons.</p>

<h3>How placement works</h3>
<p><code>Pizza::placeSaladIngredient()</code> checks if the drop is within a <strong>100px radius</strong> of the bowl centre (<code>340, 260</code>), then snaps to the same 13×13 grid and stores the sprite in <code>placedSaladIngredients</code>.</p>

<h3>Dressing buttons</h3>
<p>Two extra buttons appear only on the Salad Bar screen:</p>
<ul>
  <li><strong>add ranch</strong> — calls <code>Pizza::addKetchupSplash()</code>, placing the <code>ranch.png</code> sprite at bowl centre (<code>270, 230</code>) at <code>0.5×</code> scale.</li>
  <li><strong>add mustard</strong> — calls <code>Pizza::addmustardSplash()</code>, placing <code>mustard.png</code> at (<code>265, 225</code>) at <code>0.5×</code> scale.</li>
</ul>

<h3>Salad ingredients available</h3>
<div class="ing-grid">
  <div class="ing-cell"><strong>File</strong>lettuce-.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(30, 550)</div>
  <div class="ing-cell"><strong>File</strong>tomato.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(145, 545)</div>
  <div class="ing-cell"><strong>File</strong>onion--.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(265, 538)</div>
  <div class="ing-cell"><strong>File</strong>olive---.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(420, 550)</div>
  <div class="ing-cell"><strong>File</strong>cucumber--.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(545, 538)</div>
  <div class="ing-cell"><strong>File</strong>chicken.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(670, 545)</div>
</div>

<!-- MILKSHAKE -->
<h2 id="milkshake">🥤 Milkshake Bar</h2>

<p>The milkshake bar screen shows a top-down blender. The player drags fruits and ice cream scoops into the blender jug, then hits <strong>Blend</strong> to finish.</p>

<h3>How placement works</h3>
<p>Entering the Milkshake Bar state calls <code>Pizza::generatematrix1()</code>, which sets up a <strong>3×3 grid of <code>sf::CircleShape</code></strong> slots (radius 15px, cell size 50px) centred on the blender at (<code>400, 350</code>). <code>Pizza::placemilkingredient()</code> accepts drops within a <strong>120px radius</strong> of the blender centre, snaps to the 3×3 grid, centres the sprite on the slot, and stores it in <code>placedmilkingredients</code>.</p>

<h3>Blend button</h3>
<p>A dedicated <strong>blend</strong> button appears only on this screen. Clicking it calls <code>Pizza::addblenderimage()</code>, which places the <code>blend.png</code> blender sprite on top of all placed ingredients at (<code>270, 230</code>) at full <code>1.0×</code> scale — simulating the blending animation.</p>

<h3>Milkshake ingredients available</h3>
<div class="ing-grid">
  <div class="ing-cell"><strong>File</strong>bananas.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(5, 550)</div>
  <div class="ing-cell"><strong>File</strong>strawberry.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(135, 545)</div>
  <div class="ing-cell"><strong>File</strong>mangoes.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(265, 540)</div>
  <div class="ing-cell"><strong>File</strong>vanicecream.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(395, 550)</div>
  <div class="ing-cell"><strong>File</strong>chocolateicecream.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(515, 550)</div>
  <div class="ing-cell"><strong>File</strong>tutifrutiicecream.png</div>
  <div class="ing-cell"><strong>Spawn position</strong>(650, 550)</div>
</div>

<!-- ORDERS -->
<h2 id="orders">📋 Random Order System</h2>

<p>The <code>Order</code> class generates a random customer order each time the player visits the Order screen. It uses <code>rand() % 3</code> to pick one of three order types:</p>

<table>
  <thead><tr><th>Type</th><th>Always includes</th><th>Random extras</th></tr></thead>
  <tbody>
    <tr>
      <td><strong>Pizza</strong></td>
      <td>—</td>
      <td>2–6 random toppings from: olives, mushrooms, onions, cheese, pepperoni, sausage</td>
    </tr>
    <tr>
      <td><strong>Salad</strong></td>
      <td>lettuce, salad dressing</td>
      <td>1–4 extras from: olives, onions, tomatoes, chicken, cucumbers, mustard</td>
    </tr>
    <tr>
      <td><strong>Milkshake</strong></td>
      <td>—</td>
      <td>1–2 fruits (bananas, strawberries, mangoes) + 1–2 ice creams (vanilla, chocolate, tutifruti)</td>
    </tr>
  </tbody>
</table>

<p>The order text is rendered in the Order Screen using <code>sf::Text</code> at position (<code>100, 230</code>), font size 22, black fill — alongside a fixed chef reply at (<code>500, 350</code>) that reads: <em>"ok! coming right up play abdullah sajid's streetfighter till I prepare your pizza"</em>.</p>

<!-- ARCHITECTURE -->
<h2 id="architecture">🏗️ Project Architecture (OOP)</h2>

<p>The project strictly follows OOP — every system has its own <code>.h</code> / <code>.cpp</code> pair. All classes are declared in <code>game.h</code> and implemented across separate source files.</p>

<table>
  <thead><tr><th>Class / File</th><th>Description</th></tr></thead>
  <tbody>
    <tr><td><code>main.cpp</code></td><td>Creates the 800×800 <code>sf::RenderWindow</code> titled "MAMMA MAGLIONE", instantiates <code>Game</code>, and calls <code>game.run()</code>.</td></tr>
    <tr><td><code>Game</code> (game.cpp)</td><td>Core engine. Owns all objects, manages <code>gamestate</code>, drives the main loop (<code>handleEvents → update → render</code>), handles drag-and-drop input, and loads all textures/font/music.</td></tr>
    <tr><td><code>Pizza</code> (pizza.cpp)</td><td>Manages three separate ingredient lists (<code>placedIngredients</code>, <code>placedSaladIngredients</code>, <code>placedmilkingredients</code>) and the slot grid. Handles placement logic with circle-boundary checks and grid snapping for all three bars.</td></tr>
    <tr><td><code>Ingredients</code> (ingredient.cpp)</td><td>Each ingredient — texture, sprite, spawn position. Loads from file, scales to 0.25×, and <code>respawn()</code> resets its position after a drop.</td></tr>
    <tr><td><code>Order</code> (oreder.cpp)</td><td>Randomly generates pizza / salad / milkshake orders using <code>rand()</code>. Renders two <code>sf::Text</code> objects: the order text and the chef's fixed reply.</td></tr>
    <tr><td><code>Button</code> (button.cpp)</td><td>Rectangular button with cream normal colour and dark-red hover colour. Label uses <em>hot-pizza.normal.ttf</em> at size 30, red fill, green outline. Handles hover via <code>update()</code> and click detection via <code>isClicked()</code>.</td></tr>
    <tr><td><code>UImanager</code> (UImanager.cpp)</td><td>Holds a <code>vector&lt;Button&gt;</code>. Delegates draw, update, and event handling to each button. Supports <code>clearbutton()</code> so the nav bar can be rebuilt on each screen transition.</td></tr>
    <tr><td><code>AudioManager</code> (audio.cpp)</td><td>Wraps <code>sf::Music</code>. Opens a file, sets loop to true, and plays immediately. Used to start <code>Mambo Italiano.ogg</code> on game launch.</td></tr>
  </tbody>
</table>

<h3>Project Tree</h3>
<pre>
MAMMA-MAGLIONE/
├── <span class="k">src/</span>
│   ├── main.cpp
│   ├── game.h              <span class="c">// all class declarations</span>
│   ├── game.cpp            <span class="c">// Game class — main loop, input, render</span>
│   ├── pizza.cpp           <span class="c">// Pizza class — placement & grid logic</span>
│   ├── ingredient.cpp      <span class="c">// Ingredients class — sprite + respawn</span>
│   ├── oreder.cpp          <span class="c">// Order class — random order generation</span>
│   ├── button.cpp          <span class="c">// Button class — UI button</span>
│   ├── UImanager.cpp       <span class="c">// UImanager class — button manager</span>
│   └── audio.cpp           <span class="c">// AudioManager class — BGM</span>
├── <span class="k">assets/</span>
│   ├── outside.png         <span class="c">// homepage background</span>
│   ├── order.png           <span class="c">// order screen background</span>
│   ├── cooking station.png <span class="c">// kitchen background</span>
│   ├── oven.jpeg           <span class="c">// oven screen background</span>
│   ├── salad bar.png       <span class="c">// salad bar background</span>
│   ├── milkshakebar.jpeg   <span class="c">// milkshake bar background</span>
│   ├── blend.png           <span class="c">// blender overlay sprite</span>
│   ├── ranch.png           <span class="c">// ranch dressing splash</span>
│   ├── mustard.png         <span class="c">// mustard splash</span>
│   ├── <span class="g">hot-pizza.normal.ttf</span><span class="c">// custom display font (all UI text)</span>
│   ├── <span class="g">Mambo Italiano.ogg</span>  <span class="c">// looping background music</span>
│   ├── <span class="c">// pizza ingredients:</span>
│   │   olive-.png  cheese--.png  sausage-.png  mushroom-.png
│   │   pep--.png   onion--.png
│   ├── <span class="c">// salad ingredients:</span>
│   │   lettuce-.png  tomato.png  cucumber--.png
│   │   chicken.png   olive---.png
│   └── <span class="c">// milkshake ingredients:</span>
│       bananas.png  strawberry.png  mangoes.png
│       vanicecream.png  chocolateicecream.png  tutifrutiicecream.png
└── ooop_project.slnx       <span class="c">// Visual Studio 2022 Solution</span>
</pre>

<!-- ASSETS -->
<h2 id="assets">🎨 Assets &amp; Resources</h2>

<h3>Font</h3>
<p><strong>hot-pizza.normal.ttf</strong> — a custom pizza-themed display font used for all in-game text: button labels (size 30), order text (size 22), and the homepage team name credits (size 23). Loaded via <code>font.loadFromFile("hot-pizza.normal.ttf")</code>. Button labels use red fill with a green outline; team credits use black fill with a red outline.</p>

<h3>Background Music</h3>
<p><strong>Mambo Italiano.ogg</strong> — loaded by <code>AudioManager::start()</code> using <code>sf::Music::openFromFile()</code>. Set to loop continuously (<code>setLoop(true)</code>) and begins playing immediately on game launch. The <code>sf::Music</code> streams the file from disk rather than loading it fully into memory.</p>

<h3>Pixel-art ingredient sprites</h3>
<p>All ingredient sprites (pixel-art style) are scaled to <strong>25% of their original size</strong> at load time. The vanilla ice cream, strawberry, sausage, and tomato sprites visible in the repo are shown below — representative of the overall pixel-art visual style used across all three bars.</p>

<!-- CONTROLS -->
<h2 id="controls">🎮 Controls</h2>

<table>
  <thead><tr><th>Input</th><th>Action</th></tr></thead>
  <tbody>
    <tr><td><strong>Left click + drag</strong></td><td>Pick up an ingredient from its bowl / tray</td></tr>
    <tr><td><strong>Release left click</strong></td><td>Drop ingredient — places it if within the target zone (pizza / bowl / blender), otherwise respawns it</td></tr>
    <tr><td><strong>Order button</strong></td><td>Go to Order Screen — generates a new random order</td></tr>
    <tr><td><strong>Kitchen button</strong></td><td>Go to Pizza Kitchen — clears all placed ingredients</td></tr>
    <tr><td><strong>Oven button</strong></td><td>Go to Oven Screen</td></tr>
    <tr><td><strong>Salad bar button</strong></td><td>Go to Salad Bar — adds ranch &amp; mustard buttons</td></tr>
    <tr><td><strong>milkshake button</strong></td><td>Go to Milkshake Bar — adds blend button</td></tr>
    <tr><td><strong>add ranch / add mustard</strong></td><td>Salad Bar only — splashes dressing into the bowl</td></tr>
    <tr><td><strong>blend</strong></td><td>Milkshake Bar only — places blender overlay on ingredients</td></tr>
    <tr><td><strong>Close window</strong></td><td>Exits the game (<code>sf::Event::Closed</code>)</td></tr>
  </tbody>
</table>

<!-- BUILD -->
<h2 id="build">🚀 How to Build and Run</h2>

<h3>Prerequisites</h3>
<ul>
  <li><strong>Visual Studio 2022</strong> — recommended (MSVC compiler)</li>
  <li><strong>SFML 2.6.0</strong> for Visual C++ 17 — download from <a href="https://www.sfml-dev.org/download/sfml/2.6.0/" target="_blank">sfml-dev.org</a></li>
  <li><strong>C++17</strong> standard (<code>/std:c++17</code>)</li>
  <li><strong>Git</strong></li>
</ul>

<h3>1. Clone the repository</h3>
<pre><span class="k">git clone</span> <span class="s">https://github.com/adrakfrappe/MAMMA-MAGLIONE-.git</span>
<span class="k">cd</span> MAMMA-MAGLIONE-</pre>

<h3>2. Set up SFML 2.6.0</h3>
<p>Extract SFML to a stable path, e.g. <code>C:\SFML-2.6.0\</code>.</p>

<h3>3. Configure Visual Studio 2022</h3>
<p>Open <code>ooop_project.slnx</code>. In <strong>Project → Properties</strong>:</p>
<pre><span class="c">// C/C++ → Additional Include Directories</span>
<span class="s">C:\SFML-2.6.0\include</span>

<span class="c">// Linker → Additional Library Directories</span>
<span class="s">C:\SFML-2.6.0\lib</span>

<span class="c">// Linker → Additional Dependencies (Debug)</span>
<span class="v">sfml-graphics-d.lib  sfml-window-d.lib  sfml-system-d.lib  sfml-audio-d.lib</span>

<span class="c">// Linker → Additional Dependencies (Release)</span>
<span class="v">sfml-graphics.lib  sfml-window.lib  sfml-system.lib  sfml-audio.lib</span></pre>

<h3>4. Copy SFML DLLs &amp; assets</h3>
<p>Copy SFML <code>.dll</code> files from <code>SFML-2.6.0\bin\</code> into the output folder alongside the <code>.exe</code>. Make sure all asset files (<code>.png</code>, <code>.jpeg</code>, <code>.ttf</code>, <code>.ogg</code>) are in the <strong>same directory</strong> as the executable — the game loads them by filename with no path prefix.</p>

<div class="warn">
  <strong>⚠️ Asset loading:</strong> All textures, font, and music are loaded by bare filename (e.g. <code>"outside.png"</code>, <code>"hot-pizza.normal.ttf"</code>, <code>"Mambo Italiano.ogg"</code>). Set <em>Project → Properties → Debugging → Working Directory</em> to your assets folder so VS resolves them correctly.
</div>

<div class="note">
  <strong>ℹ️</strong> The solution file is <code>ooop_project.slnx</code> (Visual Studio 2022 format).
</div>

<h3>5. Build &amp; Run</h3>
<p>Select <strong>Debug</strong> or <strong>Release</strong>, press <code>F5</code>. An 800×800 window titled <em>"MAMMA MAGLIONE"</em> opens and <em>Mambo Italiano</em> starts playing.</p>

<!-- TEAM -->
<h2 id="team">👥 Team</h2>
<p>Homepage credits rendered in-game via <code>sf::Text</code> at startup:</p>
<div class="team-row">
  <span class="team-chip">GHAZAAL ALI</span>
  <span class="team-chip">MUAAZ IMRAN</span>
  <span class="team-chip">SHAHBAZ AHMAD</span>
</div>

<hr/>
<p class="footer-meta">
  Built with C++ &amp; SFML 2.6.0 &nbsp;·&nbsp; Font: hot-pizza.normal.ttf &nbsp;·&nbsp; BGM: Mambo Italiano.ogg &nbsp;·&nbsp;
  <a href="https://github.com/adrakfrappe/MAMMA-MAGLIONE-" target="_blank">github.com/adrakfrappe/MAMMA-MAGLIONE-</a>
</p>

</body>
</html>