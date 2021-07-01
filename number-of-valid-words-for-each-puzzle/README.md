<h2>1178. Number of Valid Words for Each Puzzle</h2><h3>Hard</h3><hr><div>With respect to a given <code>puzzle</code> string, a <code>word</code> is <em>valid</em>&nbsp;if both the following conditions are satisfied:
<ul>
	<li><code>word</code> contains the first letter of <code>puzzle</code>.</li>
	<li>For each letter in <code>word</code>, that letter is in <code>puzzle</code>.<br>
	For example, if the puzzle is "abcdefg", then valid words are "faced", "cabbage", and "baggage"; while invalid words are "beefed" (doesn't include "a") and "based" (includes "s" which isn't in the puzzle).</li>
</ul>
Return an array <code>answer</code>, where <code>answer[i]</code> is the number of words in the given word list&nbsp;<code>words</code> that are valid with respect to the puzzle <code>puzzles[i]</code>.
<p>&nbsp;</p>
<p><strong>Example :</strong></p>

<pre><strong>Input:</strong> 
words = ["aaaa","asas","able","ability","actt","actor","access"], 
puzzles = ["aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"]
<strong>Output:</strong> [1,1,3,2,4,0]
<strong>Explanation:</strong>
1 valid word&nbsp;for "aboveyz" : "aaaa" 
1 valid word&nbsp;for "abrodyz" : "aaaa"
3 valid words for "abslute" : "aaaa", "asas", "able"
2 valid words for&nbsp;"absoryz" : "aaaa", "asas"
4 valid words for&nbsp;"actresz" : "aaaa", "asas", "actt", "access"
There're&nbsp;no valid words for&nbsp;"gaswxyz" cause none of the words in the list contains letter 'g'.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= words.length &lt;= 10^5</code></li>
	<li><code>4 &lt;= words[i].length &lt;= 50</code></li>
	<li><code>1 &lt;= puzzles.length &lt;= 10^4</code></li>
	<li><code>puzzles[i].length == 7</code></li>
	<li><code>words[i][j]</code>, <code>puzzles[i][j]</code> are English lowercase letters.</li>
	<li>Each <code>puzzles[i] </code>doesn't contain repeated characters.</li>
</ul>
</div>