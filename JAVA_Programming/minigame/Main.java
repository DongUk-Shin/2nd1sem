import java.util.*; 

public class Main {      //메인 class
	public static void main(String[] args) {
		
		char[][] map = { //2차원 배열 생성
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','@','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.'} };
		
		MapCreate mapcreate = new MapCreate(map);      //참조 변수 선언 객체 생성
		try (Scanner sc = new Scanner(System.in)) {
			Monster monster = new Monster(map);
			GoldandExp goldandexp = new GoldandExp(map);
			
			System.out.println("이름 입력 : ");	//사용자에게 이름을 입력 받는다
			String nameinput = (sc.nextLine());		
			Me me = new Me(1, 1, map, nameinput);	//입력받은 문자열을 클래스의 생성자로 전달한다
			
			monster.MonsterCreate(4, 7);   //4, 7에 'M' 생성
			goldandexp.GoldCreate();       //랜덤한 위치에 'G' 생성
			mapcreate.draw(map);   		   //지도를 그린다
			
			
			boolean result = true;		 //부울 변수 선언
			while(result) {				//result면 계속 반복
				
				me.nameprint(); //이름 출력
				
				
				
				goldandexp.GoldCheck();
				goldandexp.ExpLevelPrint();
				me.Memove(sc.next()); //wasd 입력하면 x y 조절 
				monster.MonsterMove();
				result = monster.MonsterCheck();   //monster.MonsterCheck();의 값이 false면 while을 탈출한다
				mapcreate.draw(map); 
				
			}
		}
		System.out.println("Game Over!");	//반복문 탈출 후 게임 종료 문구 출력
	}
}