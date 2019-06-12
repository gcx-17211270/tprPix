/*
 * ========================= create_UIs.h ==========================
 *                          -- tpr --
 *                                        CREATE -- 2019.04.30
 *                                        MODIFY -- 
 * ----------------------------------------------------------
 */
#include "Script/UIs/create_UIs.h"

//-------------------- Engine --------------------//
#include "tprAssert.h"
#include "esrc_ui.h" 


//--------------- Script ------------------//
#include "Script/UIs/allUIs.h"
#include "Script/resource/ssrc.h"

//#include "tprDebug.h"

namespace uis{//------------- namespace uis ----------------



/* ===========================================================
 *                  create_a_ui
 * -----------------------------------------------------------
 * -- tmp 
 */
uiObjId_t create_a_ui( uiObjSpecId_t _uiObjSpecId,
                    const glm::vec2 &_fpos  ){

    uiObjId_t uiObjId = esrc::insert_new_ui();
    UIObj *uiObjPtr = esrc::get_memUIPtr( uiObjId ); //- 获取目标go指针

        tprAssert( ssrc::find_from_uiInit_funcs(_uiObjSpecId) );
        ssrc::call_uiInit_func( _uiObjSpecId, uiObjPtr, _fpos );

    //------------------------------//
        esrc::get_uiIds_active().insert( uiObjId ); //- tmp
    return  uiObjId;
}


}//------------- namespace uis: end ----------------

