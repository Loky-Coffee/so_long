<h1>So_Long - Game</h1>

<h2>Table of Contents</h2>
<ul>
  <li><a href="#introduction">Introduction</a></li>
  <li><a href="#prerequisites">Prerequisites</a></li>
  <li><a href="#building-the-project">Building the Project</a></li>
  <li><a href="#running-the-game">Running the Game</a></li>
  <li><a href="#cleaning-up">Cleaning Up</a></li>
  <li><a href="#additional-information">Additional Information</a></li>
</ul>

<h2 id="introduction">Introduction</h2>
<p>This repository contains the source code for a simple 2D game called So_Long. The game is written in C and uses the MLX42 library for graphics.</p>

<h2 id="prerequisites">Prerequisites</h2>
<p>Before you can build and run the game, make sure you have the following prerequisites:</p>
<ul>
  <li>Linux or macOS</li>
</ul>
<p>You can install the necessary dependencies using the provided script:</p>
<pre><code>make mlx</code></pre>

<h2 id="building-the-project">Building the Project</h2>
<p>To build the project, run the following command from the root directory:</p>
<pre><code>make all</code></pre>

<h2 id="running-the-game">Running the Game</h2>
<p>To run the game, use the following command:</p>
<div style="text-align: center;">
  <pre><code>./so_long ./maps/map1.ber</code></pre>
  <p>or</p>
  <pre><code>./so_long ./maps/map2.ber</code></pre>
  <p>or</p>
  <pre><code>./so_long ./maps/map3.ber</code></pre>
  <p>or</p>
  <pre><code>./so_long ./maps/map4.ber</code></pre>
  <p>or</p>
  <pre><code>./so_long ./maps/map5.ber</code></pre>
  <p>or</p>
  <pre><code>./so_long ./maps/map6.ber</code></pre>
</div>
<p>You can replace <code>./maps/map1.ber</code> with the path to your desired map file.</p>

<h2 id="cleaning-up">Cleaning Up</h2>
<p>To clean up the project (remove object files and executables), you can use the following commands:</p>
<pre><code>make clean</code></pre>

<p>To remove all built files, including the MLX42 library and <code>libft</code> objects, you can use:</p>
<pre><code>make fcleanall</code></pre>

<h2 id="additional-information">Additional Information</h2>
<ul>
  <li>This game was created as part of a 42School programming project.</li>
  <li>If you encounter any issues or have questions, please open an issue on this repository.</li>
</ul>

<p>Please note that this program is only compatible with Linux or macOS.</p>
