#include "Bullet.h"
#include "BulletsBox.h"

bool Bullet::init(float r, Vec2 v){
	if (!Node::init()){//Sprite::initWithFile("bullet.png")
		return false;
	}
	//��ʼ������
	team = 0;
	//��������
	sp = Sprite::create("bullet.png");
	//������
	this->attack = BULLETATTACK;
	//����̹�˽Ƕ���ת�ӵ�
	this->setRotation(r);
	//���ӵ���ʼλ����Ϊ̹��λ��
	auto ss = sp->getContentSize() * 5;
	switch ((int)r){
	case 0:ss.width = 0;break;
	case 90:ss.height = 0;break;
	case 180:ss.width = 0; ss.height = -ss.height;break;
	case 270:ss.height = 0; ss.width = -ss.width;break;
	default:
		break;
	}
	auto vs = v + ss;
	this->setPosition(vs);
	//���ӵ���������
	BulletsBox::getInstance()->addBullet(this);
	//�ƶ�
	BulletsMove();
	//���
	this->addChild(sp);
	return true;
}

Bullet* Bullet::create(float r, Vec2 v, int t){
	auto b = new Bullet();
	if (b && b->init(r, v)){
		b->autorelease();
		b->team = t;
		//���ݽǶ�ת���ӵ�����
		switch ((int)r){
			case 0:b->setRotation(0);break;
			case 90:b->setRotation(90);break;
			case 180:b->setRotation(180);break;
			case 270:b->setRotation(270);break;
			default:
				break;
		}
		return b;
	}
	CC_SAFE_DELETE(b);
	return nullptr;
}

//�ӵ��ƶ�����
void Bullet::BulletsMove(){
	//�����ƶ���������ֵ������Ϊ��Ļ���
	float sum = Director::getInstance()->getVisibleSize().width;
	
	//�����ƶ�ƫ����
	float moveX = 0;
	float moveY = 0;
	//�õ�λ��
	float positionBullet = 0;
	//���ݽǶȣ� λ�øı��ƶ����򣬾���

	switch ((int)(this->getRotation())){
		
		case 0:sum = Director::getInstance()->getVisibleSize().height;positionBullet = this->getPosition().y;moveY = sum - positionBullet;break;
		case 90:positionBullet = this->getPosition().x;moveX = sum - positionBullet;break;
		case 180:sum = 0;positionBullet = -this->getPosition().y;moveY = positionBullet;break;
		case 270:sum = 0;positionBullet = -this->getPosition().x;moveX = positionBullet;break;
		default:
			break;
	}
	float number = sum - positionBullet;
	//�ƶ�����
	auto move = MoveBy::create(number/BULLETSPEED, Vec2(moveX, moveY));
	auto cf = CallFunc::create([=](){
		BulletsBox::getInstance()->deleteBullet(this);
		deleteBullet();
	});
	this->runAction(Sequence::create(move, cf, NULL));
}

//ɾ��Node
void Bullet::deleteBullet(){
	this->removeFromParentAndCleanup(true);
}