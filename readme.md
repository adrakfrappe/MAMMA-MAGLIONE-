<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8"/>
<meta name="viewport" content="width=device-width, initial-scale=1.0"/>
<link rel="preconnect" href="https://fonts.googleapis.com"/>
<link href="https://fonts.googleapis.com/css2?family=Geist+Mono:wght@300;400;500&display=swap" rel="stylesheet"/>

  
</style>
</head>
<body>

<!-- REPO HEADER -->
<div class="repo-header">
  <span style="font-size:20px">📦</span>
  <span class="repo-path">adrakfrappe / <span>MAMMA-MAGLIONE</span></span>
</div>

<div class="badges">
  <span class="badge badge-blue">C++17</span>
  <span class="badge badge-orange">SFML 2.6.0</span>
  <span class="badge badge-green">OOP</span>
  <span class="badge badge-gray">Visual Studio 2022</span>
  <span class="badge badge-gray">Windows</span>
  <span class="badge badge-purple">60 FPS</span>
</div>

<hr/>

<!-- TITLE -->
<h1>🧶 MAMMA MAGLIONE</h1>
<p class="tagline">A 2D game built entirely from scratch in C++ using SFML 2.6.0</p>

<div class="about-box">
  <strong>MAMMA MAGLIONE</strong> is a handcrafted 2D game written in <strong>C++17</strong>, powered by <strong>SFML 2.6.0</strong>. Every system — from the rendering loop to collision handling — was implemented manually, without any game engine. The project follows strict <strong>Object-Oriented Programming</strong> principles, with each component encapsulated in its own <code>.h</code> / <code>.cpp</code> file pair.
</div>

<!-- TOC -->
<div class="toc">
  <div class="toc-title">Table of Contents</div>
  <ol>
    <li><a href="#features">Features</a></li>
    <li><a href="#architecture">Project Architecture</a></li>
    <li><a href="#controls">Controls</a></li>
    <li><a href="#build">How to Build &amp; Run</a></li>
    <li><a href="#troubleshooting">Troubleshooting</a></li>
  </ol>
</div>

<!-- FEATURES -->
<h2 id="features">✨ Features &amp; Functionalities</h2>

<ul>
  <li><strong>SFML 2.6.0 Rendering:</strong> All graphics, sprites, and window management handled via SFML's hardware-accelerated 2D graphics module with clean render-state management.</li>
  <li><strong>Delta-Time Game Loop:</strong> Uses <code>sf::Clock</code> and delta-time for frame-rate independent movement and logic — consistent behavior at any FPS.</li>
  <li><strong>Custom OOP Architecture:</strong> Every system (Game, Grid, Player, Entities) is fully encapsulated in its own class with clean separation of concerns.</li>
  <li><strong>Grid-Based World:</strong> A structured grid drives the game world — cell state queries, collision detection, and positional mapping through mathematical indexing.</li>
  <li><strong>Handwritten Collision Detection:</strong> No physics engine. Boundary checks and entity interactions built entirely from scratch in C++.</li>
  <li><strong>SFML Audio System:</strong> Sound effects and music via <code>sf::SoundBuffer</code> and <code>sf::Music</code>, triggered reactively by game events.</li>
  <li><strong>Texture &amp; Sprite Management:</strong> Textures loaded and cached centrally to avoid duplicate GPU uploads; sprites composed per entity.</li>
  <li><strong>Event-Driven Input:</strong> Clean input handling via <code>sf::Event</code> polling — keyboard and mouse events fully decoupled from game logic.</li>
  <li><strong>Manual Memory Management:</strong> Dynamic resources managed with <code>new</code> / <code>delete</code>, ownership semantics respected to prevent leaks.</li>
</ul>

<!-- ARCHITECTURE -->
<h2 id="architecture">🏗️ Project Architecture (OOP)</h2>

<p>This project strictly follows Object-Oriented Programming principles. Every component is encapsulated within its own Header (<code>.h</code>) and Source (<code>.cpp</code>) file.</p>

<table>
  <thead>
    <tr>
      <th>Class / File</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>main.cpp</code></td>
      <td>Entry point. Instantiates the Game object and starts the main loop.</td>
    </tr>
    <tr>
      <td><code>Constants.h</code></td>
      <td>Global config — screen size, tile size, grid dimensions, timing and gameplay values.</td>
    </tr>
    <tr>
      <td><code>Game</code></td>
      <td>Core engine. Owns the <code>sf::RenderWindow</code>, drives the delta-time loop, polls events, and coordinates all subsystems.</td>
    </tr>
    <tr>
      <td><code>Grid</code></td>
      <td>Game world grid — cell state, spatial queries, and collision checks. The spatial backbone all entities operate against.</td>
    </tr>
    <tr>
      <td><code>Player</code></td>
      <td>Player entity — movement input, animation state, and interaction with the grid and other objects.</td>
    </tr>
    <tr>
      <td><code>Entity</code></td>
      <td>Base class for all interactive game objects. Provides shared position, sprite, and update/render interfaces.</td>
    </tr>
    <tr>
      <td><code>TextureManager</code></td>
      <td>Centralized texture loading and caching. Prevents duplicate GPU uploads; provides sprites on demand.</td>
    </tr>
    <tr>
      <td><code>SoundManager</code></td>
      <td>Audio playback using <code>sf::SoundBuffer</code> and <code>sf::Music</code>, triggered by game events.</td>
    </tr>
  </tbody>
</table>

<h3>Project Tree</h3>
<pre>
MAMMA-MAGLIONE/
├── <span class="k">src/</span>
│   ├── main.cpp
│   ├── Constants.h
│   ├── Game.h            Game.cpp
│   ├── Grid.h            Grid.cpp
│   ├── Player.h          Player.cpp
│   ├── Entity.h          Entity.cpp
│   ├── TextureManager.h  TextureManager.cpp
│   └── SoundManager.h    SoundManager.cpp
├── <span class="k">assets/</span>
│   ├── textures/
│   └── sounds/
└── MAMMA-MAGLIONE.sln    <span class="c">// Visual Studio 2022 Solution</span>
</pre>

<!-- CONTROLS -->
<h2 id="controls">🎮 Controls</h2>

<table>
  <thead>
    <tr>
      <th>Key</th>
      <th>Action</th>
    </tr>
  </thead>
  <tbody>
    <tr><td><code>← / →</code></td><td>Move player left or right</td></tr>
    <tr><td><code>↑</code></td><td>Jump / move up</td></tr>
    <tr><td><code>↓</code></td><td>Crouch / accelerate downward</td></tr>
    <tr><td><code>Space</code></td><td>Primary action — attack or interact</td></tr>
    <tr><td><code>R</code></td><td>Restart / reset current game state</td></tr>
    <tr><td><code>ESC</code></td><td>Pause or close the game window</td></tr>
  </tbody>
</table>

<!-- BUILD -->
<h2 id="build">🚀 How to Build and Run</h2>

<h3>Prerequisites</h3>
<ul>
  <li><strong>Visual Studio 2022</strong> — recommended IDE (includes MSVC compiler)</li>
  <li><strong>SFML 2.6.0</strong> for Visual C++ 17 — download from <a href="https://www.sfml-dev.org/download/sfml/2.6.0/" target="_blank">sfml-dev.org</a></li>
  <li><strong>C++17</strong> standard enabled (<code>/std:c++17</code>)</li>
  <li><strong>Git</strong> to clone the repository</li>
</ul>

<h3>1. Clone the repository</h3>
<pre><span class="k">git clone</span> <span class="s">https://github.com/adrakfrappe/MAMMA-MAGLIONE-.git</span>
<span class="k">cd</span> MAMMA-MAGLIONE-</pre>

<h3>2. Set up SFML 2.6.0</h3>
<p>Download SFML 2.6.0 binaries for Visual C++ 17 from the official site. Extract to a stable path such as <code>C:\SFML-2.6.0\</code>.</p>

<h3>3. Configure Visual Studio 2022</h3>
<p>Open <code>MAMMA-MAGLIONE.sln</code>. In <strong>Project → Properties</strong>, configure:</p>
<pre><span class="c">// C/C++ → Additional Include Directories</span>
<span class="s">C:\SFML-2.6.0\include</span>

<span class="c">// Linker → Additional Library Directories</span>
<span class="s">C:\SFML-2.6.0\lib</span>

<span class="c">// Linker → Additional Dependencies (Debug)</span>
<span class="v">sfml-graphics-d.lib</span>  <span class="v">sfml-window-d.lib</span>  <span class="v">sfml-system-d.lib</span>  <span class="v">sfml-audio-d.lib</span>

<span class="c">// Linker → Additional Dependencies (Release)</span>
<span class="v">sfml-graphics.lib</span>  <span class="v">sfml-window.lib</span>  <span class="v">sfml-system.lib</span>  <span class="v">sfml-audio.lib</span></pre>

<h3>4. Copy SFML DLLs</h3>
<p>Copy the following from <code>SFML-2.6.0\bin\</code> into the same folder as your compiled <code>.exe</code>:</p>
<pre>sfml-graphics-2.dll  sfml-window-2.dll  sfml-system-2.dll  sfml-audio-2.dll  openal32.dll</pre>

<h3>5. Build &amp; Run</h3>
<p>Select <strong>Debug</strong> or <strong>Release</strong>, then press <code>F5</code> or click <strong>Local Windows Debugger</strong>. The game window will launch.</p>

<!-- TROUBLESHOOTING -->
<h2 id="troubleshooting">🔧 Troubleshooting</h2>

<div class="warn">
  <strong>⚠️ DLL not found on launch:</strong> Make sure all SFML <code>.dll</code> files are copied into the same directory as the built <code>.exe</code>.
</div>

<div class="warn">
  <strong>⚠️ Linker errors:</strong> Check that include/lib paths point to the correct SFML folder, and that you're using the <code>-d</code> suffix libs for Debug builds.
</div>

<div class="warn">
  <strong>⚠️ Architecture mismatch:</strong> Ensure your project platform (x86 / x64) matches the SFML binary you downloaded.
</div>

<div class="note">
  <strong>ℹ️ Missing assets at runtime:</strong> Set the working directory in VS via <em>Project → Properties → Debugging → Working Directory</em> to point to your project root where <code>assets/</code> lives.
</div>

<hr/>
<p class="footer-meta">
  Built with C++ &amp; SFML 2.6.0 &nbsp;·&nbsp; OOP &nbsp;·&nbsp; Visual Studio 2022 &nbsp;·&nbsp;
  <a href="https://github.com/adrakfrappe/MAMMA-MAGLIONE-" target="_blank">github.com/adrakfrappe/MAMMA-MAGLIONE-</a>
</p>

</body>
</html>