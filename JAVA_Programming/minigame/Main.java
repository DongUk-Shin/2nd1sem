import java.util.*; 

public class Main {      //���� class
	public static void main(String[] args) {
		
		char[][] map = { //2���� �迭 ����
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
		
		MapCreate mapcreate = new MapCreate(map);      //���� ���� ���� ��ü ����
		try (Scanner sc = new Scanner(System.in)) {
			Monster monster = new Monster(map);
			GoldandExp goldandexp = new GoldandExp(map);
			
			System.out.println("�̸� �Է� : ");	//����ڿ��� �̸��� �Է� �޴´�
			String nameinput = (sc.nextLine());		
			Me me = new Me(1, 1, map, nameinput);	//�Է¹��� ���ڿ��� Ŭ������ �����ڷ� �����Ѵ�
			
			monster.MonsterCreate(4, 7);   //4, 7�� 'M' ����
			goldandexp.GoldCreate();       //������ ��ġ�� 'G' ����
			mapcreate.draw(map);   		   //������ �׸���
			
			
			boolean result = true;		 //�ο� ���� ����
			while(result) {				//result�� ��� �ݺ�
				
				me.nameprint(); //�̸� ���
				
				
				
				goldandexp.GoldCheck();
				goldandexp.ExpLevelPrint();
				me.Memove(sc.next()); //wasd �Է��ϸ� x y ���� 
				monster.MonsterMove();
				result = monster.MonsterCheck();   //monster.MonsterCheck();�� ���� false�� while�� Ż���Ѵ�
				mapcreate.draw(map); 
				
			}
		}
		System.out.println("Game Over!");	//�ݺ��� Ż�� �� ���� ���� ���� ���
	}
}