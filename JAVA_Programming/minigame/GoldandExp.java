

class GoldandExp {
	int goldx, goldy; //골드의 x,y 값 변수
	int exp = 0;      //경험치 초기화
	int level = 1;    //레벨 초기화
	int random0to9, random0to19; //랜덤 값 저장을 위한 변수 선언
	int CumulEXP;     //누적 경험치 변수 
	char map [][];    //main에서 전달받을 배열 선언
	
	public GoldandExp(char map[][]) { //생성자, this.를 이용해   
		this.map = map;	}			  //Main에서 배열을 전달 받는다
		
	
	public void GoldCreate() {        //골드 생성 메소드
		random0to9 = (int)(Math.random() * 9);  
		random0to19 = (int)(Math.random() * 19);
		goldx = random0to9;     //0~9, 0~19의 정수를 생성하여
		goldy = random0to19;    //배열의 랜덤한 위치에 G를 대입한다
		map [goldx][goldy] = 'G'; }
		
	public void ExpLevelPrint() { //exp, level, 누적exp를 출력하는 메소드
		System.out.println("다음 레벨까지 " + 
				        (2-exp) + " 남았습니다");
		System.out.println("현재 레벨 " + level + 
				        " / 누적 경험치 " + CumulEXP);	}
	
	public void GoldCheck() { //G가 닿았는지 판별하는 메소드
		if (map [goldx][goldy] == '@') { //@와 G의 위치가 동일하면
			exp++;				//경험치 증가
			CumulEXP++; 		//누적 경험치 증가
			if (exp == 2) {     //만약 경험치가 2에 도달하면
				exp = 0;		//경험치 0으로 초기화
				level++; }		//레벨 1 증가
			GoldCreate(); }		//골드 생성 메소드 호출
		if (map [goldx][goldy] == 'M') { //@와 M의 위치가 동일하면
			GoldCreate(); }		//골드 생성 메소드 호출
	}
}