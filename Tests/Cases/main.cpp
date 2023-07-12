#include "test_transformRagingBerserk.cpp"
#include "test_transformCursedKnight.cpp"
#include "test_transformArtefactCompression.cpp"
#include "test_statelessCardCopyVsExactCopy.cpp"
#include "test_stateCopyVsExactCopy.cpp"
#include "test_selectingImmuneWerewolf.cpp"
#include "test_powerRow.cpp"
#include "test_optionsMandrake.cpp"
#include "test_isIn.cpp"
#include "test_highestsAndLowests.cpp"
#include "test_hasNoDuplicates.cpp"
#include "test_hasExactTwoDuplicatesOfBronze.cpp"
#include "test_firstsAndLasts.cpp"
#include "test_exactCopyDolBlathannaArcher.cpp"
#include "test_dolBlathannaArcherSeparatedShots.cpp"
#include "test_defaultCopyHalfElfHunter.cpp"
#include "test_createFilavandrel.cpp"


int main()
{
    return 0
            + transformRagingBerserk()
            + transformCursedKnight()
            + transformArtefactCompression()
            + statelessCardCopyVsExactCopy()
            + stateCopyVsExactCopy()
            + selectingImmuneWerewolf()
            + powerRow()
            + optionsMandrake()
            + isIn()
            + highestsAndLowests()
            + hasNoDuplicates()
            + hasExactTwoDuplicatesOfBronze()
            + firstsAndLasts()
            + exactCopyDolBlathannaArcher()
            + dolBlathannaArcherSeparatedShots()
            + defaultCopyHalfElfHunter()
            + createFilavandrel()
            ;
}
