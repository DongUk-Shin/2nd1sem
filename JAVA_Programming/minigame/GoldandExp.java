

class GoldandExp {
	int goldx, goldy; //����� x,y �� ����
	int exp = 0;      //����ġ �ʱ�ȭ
	int level = 1;    //���� �ʱ�ȭ
	int random0to9, random0to19; //���� �� ������ ���� ���� ����
	int CumulEXP;     //���� ����ġ ���� 
	char map [][];    //main���� ���޹��� �迭 ����
	
	public GoldandExp(char map[][]) { //������, this.�� �̿���   
		this.map = map;	}			  //Main���� �迭�� ���� �޴´�
		
	
	public void GoldCreate() {        //��� ���� �޼ҵ�
		random0to9 = (int)(Math.random() * 9);  
		random0to19 = (int)(Math.random() * 19);
		goldx = random0to9;     //0~9, 0~19�� ������ �����Ͽ�
		goldy = random0to19;    //�迭�� ������ ��ġ�� G�� �����Ѵ�
		map [goldx][goldy] = 'G'; }
		
	public void ExpLevelPrint() { //exp, level, ����exp�� ����ϴ� �޼ҵ�
		System.out.println("���� �������� " + 
				        (2-exp) + " ���ҽ��ϴ�");
		System.out.println("���� ���� " + level + 
				        " / ���� ����ġ " + CumulEXP);	}
	
	public void GoldCheck() { //G�� ��Ҵ��� �Ǻ��ϴ� �޼ҵ�
		if (map [goldx][goldy] == '@') { //@�� G�� ��ġ�� �����ϸ�
			exp++;				//����ġ ����
			CumulEXP++; 		//���� ����ġ ����
			if (exp == 2) {     //���� ����ġ�� 2�� �����ϸ�
				exp = 0;		//����ġ 0���� �ʱ�ȭ
				level++; }		//���� 1 ����
			GoldCreate(); }		//��� ���� �޼ҵ� ȣ��
		if (map [goldx][goldy] == 'M') { //@�� M�� ��ġ�� �����ϸ�
			GoldCreate(); }		//��� ���� �޼ҵ� ȣ��
	}
}