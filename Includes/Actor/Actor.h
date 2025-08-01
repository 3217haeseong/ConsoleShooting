#pragma once

#include "Core.h"
#include "Math/Vector2.h"
#include "Math/Color.h"
#include "RTTI.h"

// 물체 뭘해야할까?를 정의.
// 위치 점령.
// 콘솔 창에 그리기 (How?What?).
// 엔진의 이벤트 함수 호출.
// BeginPlay/Tick/Draw.

//전방 선언.
class Level;
class Engine_API Actor : public RTTI
{
	friend class Level;
	RTTI_DECLARATIONS(Actor, RTTI)

public:
	Actor(const char* image = "",
		Color color = Color::White,
		const Vector2& position = Vector2::Zero);

	virtual ~Actor();
	
	// 이벤트 함수. 

	// 객체 생애주기(Lifetime)에 1번만 호출됨 (초기화 목적).
	virtual void BeginPlay();  
	
	// 프레임마다 호출 (반복성 작업/ 지속성이 필요한 작업).
	virtual void Tick(float deltaTime);

	// 그리기 함수. 
	virtual void Render();

	// BeginPlay 호출 확인 여부.
	inline bool HasBeganPlay() const { return hasBeganPlay; }

	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

	// 문자열 길이 반환.
	int Width() const;
	
	// Soring Order 설.
	void SetSortingOrder(unsigned int sortingOrder);

	// 오너십 설정.
	void SetOwner(Level* newOwner);
	Level* GetOwner();

	// 충돌 확인 요청 함수 (간단한 AABB 로직).
	bool TestIntersect(const Actor* const other);

	// 객체 삭제 함수.
	void Destroy();

	// 게임 종료 요청 함수.
	void QuitGame();

protected:
	// 개체의 위치.
	Vector2 position;

	// 그릴 값.
	//char image = ' ';
	char* image = nullptr;

	// 문자열 길이.
	int width = 0;

	// 텍스트 색상 값.
	Color color;

	// BeginPlay 호출이 되었는지 확인.
	bool hasBeganPlay = false;

	// 정렬 순서.
	unsigned int sortingOrder = 0;

	// 액터가 활성 상태인지 알려주는 변수.
	bool isActive = true;

	// 삭제 요청됐는지 알려주는 변수.
	bool isExpired = false;

	// 소유 레벨(오너십)
	Level* owner = nullptr;
	
};