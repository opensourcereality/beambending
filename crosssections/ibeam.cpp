#include "ibeam.h"
#include "ibeamform.h"

IBeam::IBeam(double width, double height, double internalWidth, double internalHeight)
{
    this->width = width;
    this->height = height;
    this->internalWidth = internalWidth;
    this->internalHeight = internalHeight;
    this->name = "IBeam";
}

void IBeam::SetWidth(double width) {
    this->width = width;
}

double IBeam::GetWidth() const {
    return width;
}

void IBeam::SetInternalWidth(double internalWidth) {
    this->internalWidth = internalWidth;
}

double IBeam::GetInternalWidth() const {
    return internalWidth;
}

void IBeam::SetInternalHeight(double internalHeight) {
    this->internalHeight = internalHeight;
}

double IBeam::GetInternalHeight() const {
    return internalHeight;
}

void IBeam::SetHeight(double height) {
    this->height = height;
}

double IBeam::GetHeight() const {
    return height;
}

double IBeam::getInertiaAreaMoment()
{
    double b = width, d = height, h = internalHeight, t = internalWidth;
    return ((b*d*d*d) - ((h*h*h)*(b-t)))/12.0;
}

double IBeam::getDiatanceFromNeutralAxis()
{
    return height/2.0;
}

void IBeam::constructForm(double beamLength, QWidget *parent)
{
    this->form = new IBeamForm(this, beamLength, parent);
}
