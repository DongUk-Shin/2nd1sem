import java.util.*; 

class Me { //나(캐릭터)를 다루는 클래스
	int x, y;		//캐릭터의 x, y값을 저장할 변수 선언
	char map [][];  //main에서 전달받을 배열 선언
	String name;	//사용자에게 입력받은 텍스트를 저장하는 변수 선언
	
	public Me(int x, int y, char map [][], String name) { 
		this.x = x;             //생성자, this.를 이용해
		this.y = y;				//Main에서 입력한 캐릭터의 x,y 값을 받는다
		this.map = map;			//Main에서 배열을 전달 받는다
		this.name = name; }		//사용자에게 입력받은 String을 받는다
	
	public void nameprint() {  //Main에서 입력 받은 이름(String)을 출력하는 메소드
		System.out.println("캐릭터 이름 " + name ); } 
		
	public void Memove(String enter) { 		//사용자에게 입력 받은 값을 대조해 캐릭터를 움직이는 메소드
		if(enter.equals("a") && y > 0) {	//x, y의 값이 배열 인덱스 내의 값인지 판별, 키보드 입력
			map [x][y] = '.';				//원래 있던 자리에 .을 남긴다
			y--; } 							//캐릭터의 y 좌표조절
		else if(enter.equals("d") &&  y < 19) {	
			map [x][y] = '.'; 
			y++; } 
		else if(enter.equals("w") && x > 0) {
			map [x][y] = '.'; 
			x--; }
		else if(enter.equals("s") && x < 9) {
			map [x][y] = '.'; 
			x++; }
		
		map [x][y] = '@'; 					//wasd로 조절된 x, y 의 값에 캐릭터를 대입한다
	}
}