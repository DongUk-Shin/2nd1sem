 

class Me { //��(ĳ����)�� �ٷ�� Ŭ����
	int x, y;		//ĳ������ x, y���� ������ ���� ����
	char map [][];  //main���� ���޹��� �迭 ����
	String name;	//����ڿ��� �Է¹��� �ؽ�Ʈ�� �����ϴ� ���� ����
	
	public Me(int x, int y, char map [][], String name) { 
		this.x = x;             //������, this.�� �̿���
		this.y = y;				//Main���� �Է��� ĳ������ x,y ���� �޴´�
		this.map = map;			//Main���� �迭�� ���� �޴´�
		this.name = name; }		//����ڿ��� �Է¹��� String�� �޴´�
	
	public void nameprint() {  //Main���� �Է� ���� �̸�(String)�� ����ϴ� �޼ҵ�
		System.out.println("ĳ���� �̸� " + name ); } 
		
	public void Memove(String enter) { 		//����ڿ��� �Է� ���� ���� ������ ĳ���͸� �����̴� �޼ҵ�
		if(enter.equals("a") && y > 0) {	//x, y�� ���� �迭 �ε��� ���� ������ �Ǻ�, Ű���� �Է�
			map [x][y] = '.';				//���� �ִ� �ڸ��� .�� �����
			y--; } 							//ĳ������ y ��ǥ����
		else if(enter.equals("d") &&  y < 19) {	
			map [x][y] = '.'; 
			y++; } 
		else if(enter.equals("w") && x > 0) {
			map [x][y] = '.'; 
			x--; }
		else if(enter.equals("s") && x < 9) {
			map [x][y] = '.'; 
			x++; }
		
		map [x][y] = '@'; 					//wasd�� ������ x, y �� ���� ĳ���͸� �����Ѵ�
	}
}