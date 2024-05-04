# [Gold IV] Tichu - 3658 

[문제 링크](https://www.acmicpc.net/problem/3658) 

### 성능 요약

메모리: 2096 KB, 시간: 280 ms

### 분류

백트래킹, 비트마스킹, 다이나믹 프로그래밍, 구현, 재귀

### 제출 일자

2023년 10월 11일 12:19:49

### 문제 설명

<p>Tichu is a card game played by four players. The players sit around a square table, and each player forms a team with the person sitting opposite him or her. The game is played with a standard deck of cards and four additional special cards. The basic rule of the game is as follows: the player who won the last trick can start a new trick with any legal combination of cards. Then, in turn, each next player can either pass or play the same combination of cards, but with a higher value. This continues until everyone passes, and at that point the player who played the last combination wins the trick and can start a new trick. The main goal is to get rid of all of your cards as soon as possible.</p>

<p>These basic rules make it a good tactic to combine the cards in such a way that they can be played in as few combinations as possible. For simplicity we consider here a slightly modified version of the game. We ignore the special cards, so that leaves a standard deck of 52 cards, ranging over the values 2 to <code>Ace</code> and over the suits <code>hearts</code>, <code>diamonds</code>, <code>clubs</code>, and <code>spades</code>. The suits are indicated by the lowercase letters <code>h</code>, <code>d</code>, <code>c</code>, and <code>s</code>, while the values are indicated in increasing order by <code>2–9</code>, <code>T</code>, <code>J</code>, <code>Q</code>, <code>K</code>, <code>A</code>. The following list is a complete set of legal combinations:<sup>1</sup></p>

<ul>
	<li>any single card;</li>
	<li>a pair of cards of the same value;</li>
	<li>three cards of the same value;</li>
	<li>four cards of the same value;</li>
	<li>a full house, that is, three cards of the same value and two cards of another, same value, for example <code>444KK</code>;</li>
	<li>a straight of length at least five, that is, at least five cards of consecutive increasing values, for example <code>89TJQK</code>.</li>
</ul>

<p>In this problem, your task is to determine the minimum number of combinations that your hand of 13 cards can be partitioned into.</p>

<p><sup>1</sup>Those who know the game of Tichu might have noticed that we removed consecutive pairs of cards as a valid combination.</p>

### 입력 

 <p>On the first line a positive integer: the number of test cases, at most 100. After that per test case:</p>

<ul>
	<li>one line that describes your hand of 13 cards. The card descriptions are separated by single spaces. A card is described by two characters: the value followed by the suit. All cards in your hand are different.</li>
</ul>

### 출력 

 <p>Per test case:</p>

<ul>
	<li>one line containing an integer n: the minimum number of combinations that your hand can be partitioned into.</li>
	<li>n lines that describe a minimal set of combinations of cards from your hand. Each line should contain the cards in one legal combination, in the same format as in the input. All cards from your hand must occur exactly once in one of the combinations. No specific ordering of the combinations or the cards within a combination is required.</li>
</ul>

