#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

//Animal이라는 기본 클래스 정의
class Animal {
//Animal 클래스에는 makeSound()라는 순수 가상 함수 포함
public:
	virtual void makeSound() const = 0;
	virtual ~Animal() {}
};
//Animal 클래스를 상속받아 다양한 동물 클래스 생성
//또한, 각 클래스에서 makeSound() 함수를 재정의하여 해당 동물의 소리를 출력
class Dog : public Animal {
public:
	void makeSound() const override {
		cout << "WoofWoof" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() const override {
		cout << "MeowMeow" << endl;
	}
};

class Cow : public Animal {
public:
	void makeSound() const override {
		cout << "Moo~" << endl;
	}
};

class Zoo {
private:
	Animal* animals[10]; // 동물 객체를 저장하는 포인터 배열
	int cnt = 0;

public:
	// 동물을 동물원에 추가하는 함수
	// Animal 객체의 포인터*를 받아서 포인터 배열에 저장.
	// 입력 매개변수: Animal*
	// void
	void addAnimal(Animal* animal) {
		if (cnt < 10) {
			animals[cnt++] = animal;
		}
		else {
			cout << "동물의 수가 10마리를 넘었습니다." << endl;
		}
	}
	// 동물원에 있는 모든 동물의 행동을 수행하는 함수
	// 모든 객체가 순차적으로 행동한다.
	// 입력 매개변수: 없음
	// void
	void performActions() {
		for (int i = 0; i < cnt; ++i) {
			animals[i]->makeSound();
		}
	}
	// Zoo 소멸자
	// 메모리 누수 방지를 위해 Animal 객체 'delete'
	~Zoo() {
		for (int i = 0; i < cnt; ++i) {
			delete animals[i];
		}
	}
};

//랜덤 동물을 생성하는 함수
//0, 1, 2 중 난수 생성... 각 동물을 동적으로 생성
//그 객체들은 포인터로 반환
Animal* createRandomAnimal() {
	int random = rand() % 3;
	switch (random) {
	case 0:
		return new Dog();
	case 1:
		return new Cat();
	case 2:
		return new Cow();
	default:
		return 0;
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	//Animal 타입의 포인터 배열 선언.
	//vector<Animal*> animals;
	//Dog, Cat, Cow 자료형의 변수를 선언하고, 배열에 저장
	//Dog dog;
	//Cat cat;
	//Cow cow;
	//Animal 배열을 반복문으로 순회하면서 동물 울음소리 출력
	//animals.push_back(&dog);
	//animals.push_back(&cat);
	//animals.push_back(&cow);

	//for (Animal* animal : animals) {
	//	animal->makeSound();
	//}

	Zoo zoo;

	for (int i = 0; i < 5; ++i) {
		Animal* randomAnimal = createRandomAnimal();
		zoo.addAnimal(randomAnimal);
	}

	//zoo.addAnimal(new Dog());
	//zoo.addAnimal(new Cat());
	//zoo.addAnimal(new Cow());
	//zoo.addAnimal(new Cat());
	//zoo.addAnimal(new Cow());

	zoo.performActions();

	return 0;
}