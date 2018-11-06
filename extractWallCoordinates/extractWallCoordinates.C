#include "fvMesh.H"
#include "volFields.H"
#include "Time.H"
#include "argList.H"

using namespace Foam;

int main(int argc, char *argv[])
{
    # include "addTimeOptions.H"
    argList::validArgs.append("patch");

    # include "setRootCase.H"
    # include "createTime.H"
    # include "createMesh.H"

    Info<< "Dump face centres of given patch\n" << endl;
    const word patchName = args[1];
    label patchI = mesh.boundaryMesh().findPatchID(patchName);
    const polyPatch& pp = mesh.boundaryMesh()[patchI];

    Info<<pp.faceCentres().size()<<endl;
    Info<<"("<<endl;
    forAll(pp.faceCentres(), faceI)
    {
        scalar x = pp.faceCentres()[faceI].x();
        scalar y = pp.faceCentres()[faceI].y();
        scalar z = pp.faceCentres()[faceI].z();
        Info<<"("<<x<<" "<<y<<" "<<z<<")"<<endl;
    }
    Info<<")"<<endl;

    return 0;
}
