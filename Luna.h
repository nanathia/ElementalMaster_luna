
#ifndef __Stg14__Luna__
#define __Stg14__Luna__

#include "Character.h"
#include "cocos2d.h"

namespace luna{
	class LunaState;

	struct _tagTEXTURE;
	typedef struct _tagTEXTURE TEXTURE;

	class CPlayerLuna : public CCharacter{
		
		TEXTURE* m_lunaTex;
		float* m_lunaHp;
		float* m_lunaMp;
		float* m_lunaOverDrive;
		int m_jumpHoldCounter;
		int m_dashHoldCounter;
		int m_chargeHoldCounter;
		LunaState* m_lunaState;
		
	public:

		CPlayerLuna();
		~CPlayerLuna();
		
		void update(double deltaTime);
		float* getHp();
		float* getMp();
		float* getOd();
		
		// set メソッド郡
		float* setHp();
		float* setMp();
		float* setOd();
	};
}
#endif /* defined(__Stg14__Luna__) */
