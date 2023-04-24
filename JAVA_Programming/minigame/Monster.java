import java.util.*; 


class Monster {
	int x, y; 		//몬스터의 x, y좌표를 저장할 변수 선언
	int random0to3; //난수를 저장할 변수 선언
	char map [][];	//main에서 전달받을 배열 선언
	
	public Monster(char map[][]) { //생성자, this.를 이용해
		this.map = map;	}		   //Main에서 배열을 전달 받는다
	
	public void MonsterCreate(int x, int y) { //Main에서 x, y를 입력 받아 몬스터의 좌표를 지정하는 메소드
		map [x][y] = 'M'; 					//전달받은 x, y좌표에 M 대입
		this.x = x;							//이후 전달받은 x, y는 클래스의 변수로 사용하기 위해 this.를 사용
		this.y = y; }
	
	public void MonsterMove(){   //몬스터의 움직이는 메소드 (부울)
		random0to3 = (int)(Math.random() * 4); //메소드가 호출 될 때마다
											   //0 ~ 3 의 난수를 생성한다
		if (random0to3 == 0 && y > 0) {		//x, y의 값이 인덱스 내의 값인지 판별
			if (map [x][y] != '@') {		//몬스터가 있는 자리에 @가 아니라면 
				map [x][y] = '.';  } 		//. 대입 (이렇게 한 이유는 MonsterMove()보다 Memove()가 먼저 실행되기에
			y--; }							//몬스터의 좌표값 조절
		
		else if (random0to3 == 1 && y < 19) {  
			if (map [x][y] != '@') {
				map [x][y] = '.';  } 
			y++; }
		
		else if (random0to3 == 2 &&  x > 0) { 
			if (map [x][y] != '@') {
				map [x][y] = '.';  } 
			x--; }
		
		else if (random0to3 == 3 && x < 9) {
			if (map [x][y] != '@') {
				map [x][y] = '.';  } 
			x++;} }
		
	public boolean MonsterCheck() {	
		if (map [x][y] == '@') {  //몬스터가 움직인 좌표에 @가 있으면 
			map [x][y] = 'M';	  //조절한 x,y의 좌표에 M 출력
			return false; }       //false 반환 (Main의 While 탈출하기 위함)
		else {
			map [x][y] = 'M';	//조절한 x,y의 좌표에 M 출력
			return true; }		//그렇지 않으면 Main의 While이 계속 반복된다
	} 
}
