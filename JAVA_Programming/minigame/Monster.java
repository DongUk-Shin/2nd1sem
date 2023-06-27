 


class Monster {
	int x, y; 		//������ x, y��ǥ�� ������ ���� ����
	int random0to3; //������ ������ ���� ����
	char map [][];	//main���� ���޹��� �迭 ����
	
	public Monster(char map[][]) { //������, this.�� �̿���
		this.map = map;	}		   //Main���� �迭�� ���� �޴´�
	
	public void MonsterCreate(int x, int y) { //Main���� x, y�� �Է� �޾� ������ ��ǥ�� �����ϴ� �޼ҵ�
		map [x][y] = 'M'; 					//���޹��� x, y��ǥ�� M ����
		this.x = x;							//���� ���޹��� x, y�� Ŭ������ ������ ����ϱ� ���� this.�� ���
		this.y = y; }
	
	public void MonsterMove(){   //������ �����̴� �޼ҵ� (�ο�)
		random0to3 = (int)(Math.random() * 4); //�޼ҵ尡 ȣ�� �� ������
											   //0 ~ 3 �� ������ �����Ѵ�
		if (random0to3 == 0 && y > 0) {		//x, y�� ���� �ε��� ���� ������ �Ǻ�
			if (map [x][y] != '@') {		//���Ͱ� �ִ� �ڸ��� @�� �ƴ϶�� 
				map [x][y] = '.';  } 		//. ���� (�̷��� �� ������ MonsterMove()���� Memove()�� ���� ����Ǳ⿡
			y--; }							//������ ��ǥ�� ����
		
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
		if (map [x][y] == '@') {  //���Ͱ� ������ ��ǥ�� @�� ������ 
			map [x][y] = 'M';	  //������ x,y�� ��ǥ�� M ���
			return false; }       //false ��ȯ (Main�� While Ż���ϱ� ����)
		else {
			map [x][y] = 'M';	//������ x,y�� ��ǥ�� M ���
			return true; }		//�׷��� ������ Main�� While�� ��� �ݺ��ȴ�
	} 
}