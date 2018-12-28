#pragma once

//�����
class Player{
	friend class Game;
	friend class Scene;
public:
	Player(Game &game);

	void NewGame(void);//��ʼ�µ�һ�֣���һЩ��ʼ�����ϵȵĲ���
	void ClearAnalyse(void);//��շ����Ƽ���
	int GetBaseScore(int questioned,int nowscore);//�����Ƿ��뵱������������������
	void AddCard(int num){ cards.insert(num); }//Ĩ��
	int GetRemain(void){ return cards.size(); }//ʣ������
	bool IsValid(void);//�ж�ѡ�����Ƿ�ϸ�
	void AnalyseSelection(void);//����ѡ�������ͼ���Ȩֵ
	void DivideIntoGroups(void); //�������������
	void ThreeplusAndAirplane(void);//�ӷ�����Ļ����������������һ�ͷɻ�
	void DeleteUnkown(void);//ɾ�����ͼ�����δ֪����
	void SelectCards(bool hint=false);//AIѡ��
	void Myself();//ֱ�ӳ���
	void Friend();//���ѷ���
	void Enemy(bool hint);//���з���
	void NeedSigle();//�������
	void NeedDouble();
	void NeedSigleSeq();
	void NeedThreePlus();
	void NeedAirplane();
	bool Discard(void); //AI����
	bool HumanDiscard();//��ҳ���
	bool DiscardAndClear();//���Ʋ�������Ӧ�ṹ
	//void Hint(void); //��ʾ��
	void Pass(void);//���ƣ�������Ӧ�ṹ
	//����Ȩֵ���Ӽ����в�����Ӧ0-53���֣�Ȼ��Ӽ�����ɾ�������ظ����֣������ڻ���Ч����-1
	int ValueToNum(std::set<int> &cardscopy, int value);
	void FreshenMap(std::map<int, int> &m);//ɾ��������������Ϊ���Ԫ��
	static bool MyCompare(CardGroup *c1, CardGroup *c2);//�Է������Ƽ�������Ļص�����


	bool IsDiscardDirplane();

private:
	Game &game;//��Ϸ����
	bool test;//�Ƿ��Թ����¼���
	bool nodiscard;//������־
	int score;//��ҵ�ǰ����
	std::set<int> cards;//����
	std::vector<CardGroup*> analyse;//�������ֵ����ͼ���

	std::vector<CardGroup*> behaviors;//�Լ���Ϊ��¼
	std::set<Type> records[3]; //������ҳ��Ʋ�Ҫ���ͼ�¼(��ʱ��)

	std::set<int> remainCards; //������


	CardGroup selection;//ѡ���Ƶļ���
	CardGroup discard;//������Ƶļ���
};