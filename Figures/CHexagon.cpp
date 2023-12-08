#include "CHexagon.h"

CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) : CFigure(FigureGfxInfo)
{
	Center = P1;

}


void CHexagon::Draw(Output* pOut) const
{

	pOut->DrawHex(Center, FigGfxInfo, Selected);
}


bool CHexagon::IsInclude(Point P) const
{

    double sideLength = 150; // ANAS IBRAHEM OPTIMIZE DRAGGING
    double verticesX[6];
    double verticesY[6];
    const long double M_PI = 3.141592653589793238L;

    for (int i = 0; i < 6; ++i) {
        verticesX[i] = Center.x + sideLength * cos(2.0 * M_PI * i / 6.0);
        verticesY[i] = Center.y + sideLength * sin(2.0 * M_PI * i / 6.0);
    }

    // Calculate barycentric coordinates
    double detT = (verticesY[2] - verticesY[4]) * (verticesX[1] - verticesX[4]) +
        (verticesX[4] - verticesX[2]) * (verticesY[1] - verticesY[4]);

    double alpha = ((verticesY[2] - verticesY[4]) * (P.x - verticesX[4]) +
        (verticesX[4] - verticesX[2]) * (P.y - verticesY[4])) / detT;

    double beta = ((verticesY[4] - verticesY[0]) * (P.x - verticesX[4]) +
        (verticesX[0] - verticesX[4]) * (P.y - verticesY[4])) / detT;

    double gamma = 1.0 - alpha - beta;

    // Check if the point is inside the hexagon
    return alpha >= 0.0 && beta >= 0.0 && gamma >= 0.0;

}
