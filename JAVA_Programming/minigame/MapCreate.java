
class MapCreate {  //화면에 지도를 그리는 메소드
	char map [][]; //main에서 전달받을 배열 선언
	
	public MapCreate(char map [][]) {  //생성자, this.를 이용해  
		this.map = map; }              //Main에서 배열을 전달 받는다
	
	public void draw(char map[][]) {   //화면에 10x20 크기의
		for (int i=0; i<10; i++) {	   //지도(2차원배열)을 출력한다
			for (int j=0; j<20; j++) {
				System.out.print(map[i][j]);	}
			System.out.print("\n");		}
	}
}