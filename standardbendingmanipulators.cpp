#include "standardbendingmanipulators.h"

#include "cantilever.h"
#include "simplysupported.h"
#include "mixedsupported.h"

StandardBendingManipulators::StandardBendingManipulators(Beam *beam, Load *load)
{

    n = 3;
    //supported Materials -- stresses in N/m^2
    bendingManipulator = new BendingManipulator *[n];
    bendingManipulator[0] = new CantileverBendingManipulator(beam, load);
    bendingManipulator[1] = new SimplySupportedBendingManipulator(beam, load);
    bendingManipulator[2] = new MixedSupportedBendingManipulator(beam, load);
}
