
class MapCreate {  //ȭ�鿡 ������ �׸��� �޼ҵ�
	char map [][]; //main���� ���޹��� �迭 ����
	
	public MapCreate(char map [][]) {  //������, this.�� �̿���  
		this.map = map; }              //Main���� �迭�� ���� �޴´�
	
	public void draw(char map[][]) {   //ȭ�鿡 10x20 ũ����
		for (int i=0; i<10; i++) {	   //����(2�����迭)�� ����Ѵ�
			for (int j=0; j<20; j++) {
				System.out.print(map[i][j]);	}
			System.out.print("\n");		}
	}
}