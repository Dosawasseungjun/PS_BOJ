# [Platinum IV] 기둥만들기 - 2598 

[문제 링크](https://www.acmicpc.net/problem/2598) 

### 성능 요약

메모리: 2172 KB, 시간: 496 ms

### 분류

브루트포스 알고리즘, 구현

### 제출 일자

2025년 2월 14일 20:54:25

### 문제 설명

<p>주사위 모양의 정육면체에 각 면이 빨강(R), 초록(G), 파랑(B), 노랑(Y) 가운데 어떤 색으로 칠해져 있다. 이러한 정육면체 4개를 기둥 모양으로 쌓아 올려서 기둥의 각 옆면에 4가지 색이 모두 나타나게 하고 싶다. 이러한 기둥을 모두 몇 개나 만들 수 있는지 구하는 프로그램을 작성하시오.</p>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src=""><img alt="" src="https://upload.acmicpc.net/3e0f7493-5d11-457a-b7e3-0d7f58353ad5/-/crop/135x148/5,0/-/preview/" style="width: 68px; height: 74px;"></td>
			<td><img alt="" src=""><img alt="" src="https://upload.acmicpc.net/3e0f7493-5d11-457a-b7e3-0d7f58353ad5/-/crop/135x148/140,0/-/preview/" style="width: 68px; height: 74px;"></td>
			<td><img alt="" src=""><img alt="" src="https://upload.acmicpc.net/3e0f7493-5d11-457a-b7e3-0d7f58353ad5/-/crop/135x148/274,0/-/preview/" style="width: 68px; height: 74px;"></td>
			<td><img alt="" src=""><img alt="" src="https://upload.acmicpc.net/3e0f7493-5d11-457a-b7e3-0d7f58353ad5/-/crop/137x148/408,0/-/preview/" style="width: 69px; height: 74px;"></td>
		</tr>
		<tr>
			<td>정육면체 1</td>
			<td>정육면체 2</td>
			<td>정육면체 3</td>
			<td>정육면체 4</td>
		</tr>
		<tr>
			<td colspan="4">그림 1</td>
		</tr>
	</tbody>
</table>

<table class="table table-bordered td-center">
	<tbody>
		<tr>
			<td><img alt="" src="https://upload.acmicpc.net/b20dbd8b-a3a3-47f9-8044-3f858a940bc0/-/crop/139x406/0,0/-/preview/" style="width: 70px; height: 203px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/b20dbd8b-a3a3-47f9-8044-3f858a940bc0/-/crop/139x406/178,0/-/preview/" style="width: 70px; height: 203px;"></td>
			<td><img alt="" src="https://upload.acmicpc.net/b20dbd8b-a3a3-47f9-8044-3f858a940bc0/-/crop/139x406/355,0/-/preview/" style="width: 70px; height: 203px;"></td>
		</tr>
		<tr>
			<td>그림 2</td>
			<td>그림 3</td>
			<td>그림 4</td>
		</tr>
	</tbody>
</table>

<p>정육면체를 쌓을 때 1번 정육면체를 맨 아래에 놓고, 그 위에 2번 정육면체, 3번 정육면체, 맨 위에 4번 정육면체를 놓는다. 각 정육면체는 마음대로 위치를 바꾸어서 놓을 수 있다. 예를 들어서, 그림 1과 같은 4개의 정육면체를 쌓아서 그림 2와 그림 3의 두 개의 기둥을 만들 수 있다.</p>

<p>하지만, 기둥을 옆으로 회전시켜서 같은 모양이 되는 것은 같은 기둥으로 본다. 예를 들어서 그림 3에 있는 기둥과 그림 4에 있는 기둥은 같은 기둥이다. 기둥의 윗면의 색이 다른 것은 다른 기둥이며, 기둥의 밑면은 보이지 않으므로 고려하지 않는다.</p>

### 입력 

 <p>첫줄에는 1번 정육면체, 두 번째 줄에 2번 정육면체, 세 번째 줄에 3번 정육면체, 네 번째 줄에 4번 정육면체가 입력된다. 각 줄은 6개의 영문자로 이루어진다. 영문자는 R, G, B, Y 중의 하나이다. 6개의 영문자는 순서대로 그림 5의 가, 나, 다, 라, 마, 바 면의 색을 나타낸다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/99eec680-9bb1-41cf-8709-e01fad6f263c/-/preview/" style="height: 70px; width: 70px;"></p>

<p style="text-align: center;">그림 5</p>

### 출력 

 <p>조건을 만족하는 기둥의 개수를 출력한다. 조건을 만족하는 기둥이 하나도 만들어지지 않으면 0을 출력한다.</p>

