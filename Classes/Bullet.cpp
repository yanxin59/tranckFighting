#include "Bullet.h"
#include "BulletsBox.h"

bool Bullet::init(float r, Vec2 v){
	if (!Node::init()){//Sprite::initWithFile("bullet.png")
		return false;
	}
	//��ʼ������
	setEntityType(0);
	//�����ٶ�
	setISpeed(300);
	//��������
	setbindSprite(Sprite::create("bullet.png"));
	//������
	this->attack = BULLETATTACK;
	//����̹�˽Ƕ���ת�ӵ�
	this->setRotation(r);
	//���ӵ���ʼλ����Ϊ̹��λ�� + 2���ӵ����ȣ�Ϊ�˿����Ǵ��ڿڳ���
	auto ss = getbindSprite()->getContentSize()*2;
	auto maxs = ss.width > ss.height ? ss.width:ss.height;
	switch ((int)r){
	case 0:ss.width = 0;ss.height = maxs;break;
	case 90:ss.height = 0;ss.width = maxs;break;
	case 180:ss.width = 0; ss.height = -maxs;break;
	case 270:ss.height = 0; ss.width = -maxs;break;
	default:
		break;
	}
	auto vs = v + ss;
	this->setPosition(vs);
	//���ӵ���������
	BulletsBox::getInstance()->addBullet(this);
	//�ƶ�
	move();
	//���
	this->addChild(getbindSprite());
	return true;
}

void Bullet::doAction(){

}

Bullet* Bullet::create(float r, Vec2 v, int t){
	auto b = new Bullet();
	if (b && b->init(r, v)){
		b->autorelease();
		b->setEntityType(t);
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
void Bullet::move(){
	//�����ƶ���������ֵ������Ϊ��Ļ���
	float sum = Director::getInstance()->getVisibleSize().width;
	
	//�����ƶ�ƫ����
	float moveX = 0;
	float moveY = 0;
	//�õ�λ��
	float positionBullet = 0;
	//���ݽǶȣ� λ�øı��ƶ����򣬾���
	auto bs = this->getContentSize();
	auto maxs = bs.width > bs.height ? bs.width:bs.height;
	switch ((int)(this->getRotation())){
		
		case 0:sum = Director::getInstance()->getVisibleSize().height;positionBullet = this->getPosition().y;moveY = sum - positionBullet + maxs;break;
		case 90:positionBullet = this->getPosition().x;moveX = sum - positionBullet + maxs;break;
		case 180:sum = 0;positionBullet = -this->getPosition().y;moveY = positionBullet - maxs;break;
		case 270:sum = 0;positionBullet = -this->getPosition().x;moveX = positionBullet - maxs;break;
		default:
			break;
	}
	float number = sum - positionBullet;
	//�ƶ�����
	auto move = MoveBy::create(number/getISpeed(), Vec2(moveX, moveY));
	auto cf = CallFunc::create([=](){
		BulletsBox::getInstance()->deleteBullet(this);
		doDead();
	});
	this->runAction(Sequence::create(move, cf, NULL));
}

//ɾ��Node
void Bullet::doDead(){
	this->removeFromParentAndCleanup(true);
}