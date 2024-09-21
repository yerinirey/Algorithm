# [Gold II] Palindromic Crossword - 23017 

[문제 링크](https://www.acmicpc.net/problem/23017) 

### 성능 요약

메모리: 4332 KB, 시간: 428 ms

### 분류

그래프 이론, 그래프 탐색, 구현

### 제출 일자

2024년 9월 21일 20:05:32

### 문제 설명

<p>A <a href="https://en.wikipedia.org/wiki/Crossword" target="_blank">crossword puzzle</a> is a rectangular grid of black cells and letters <code>A-Z</code> like the one shown below.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/de3271dd-981c-432a-8774-02b1b91289ab/-/crop/242x177/0,94/-/preview/"><img alt="" src=""></p>

<p>Words in the crossword are defined as maximal vertical or horizontal segments of characters. In the crossword below, DO and ON are examples of words.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/b32ac8dc-68a8-4d4d-8074-2f565557197d/-/crop/252x174/22,47/-/preview/"></p>

<p>A palindromic crossword is one where every word is a <a href="https://en.wikipedia.org/wiki/Palindrome">palindrome</a>. Let R<sub>i,j</sub> represent the character on the i-th row and j-th column, where i and j are 1-indexed. The top left corner is R<sub>1,1</sub>. In the example palindromic crossword below, the <code>B</code> in R<sub>3,2</sub> is part of both the horizontal word starting at R<sub>3,1</sub> and the vertical word ending at R<sub>4,2</sub>, and both are palindromes.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0d245359-2698-4839-9b2a-bbaede92d379/-/crop/242x170/0,17/-/preview/"></p>

<p>You have been gifted a palindromic crossword puzzle with N rows and M columns. You finished the crossword and throw away the clues, preparing to hang it on your wall. However, you accidentally erase some of the letters! You want to recover as much of the crossword as possible, but you do not have the clues anymore. Using only the knowledge that the crossword is palindromic, restore the maximum possible number of missing characters in the given crossword.</p>

<p>Missing letters are represented as empty white cells in the below diagram. The crossword on the left is the crossword you are given and the crossword on the right is the result after you recover as many letters as possible. The remaining cells cannot be filled because we do not have sufficient information to recover them.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/74174f5a-ccdd-4646-93bd-684324d35394/-/crop/562x172/0,96/-/preview/"></p>

### 입력 

 <p>The first line of the input gives the number of test cases, T. T test cases follow.</p>

<p>The first line of each test case contains two integers, N and M, representing the number of rows and columns in the crossword, respectively.</p>

<p>The next N lines represent the N rows of the grid. The i-th row consists of M characters representing R<sub>i,1</sub>, R<sub>i,2</sub>, …, R<sub>i,M</sub>. Each character is one of the following:</p>

<ul>
	<li>A capital letter of the alphabet (<code>A-Z</code>)</li>
	<li>A period (<code>.</code>) for a missing letter (empty white cell in the example crossword)</li>
	<li>A hash (<code>#</code>) for black cell</li>
</ul>

### 출력 

 <p>For each test case, output one line containing <code>Case #x: y</code> where x is the test case number (starting from 1) and y is the number of empty white cells that were filled. Then, output N more lines representing the final grid, with the missing characters (<code>.</code>) replaced by capital letters (<code>A-Z</code>) where possible.</p>

