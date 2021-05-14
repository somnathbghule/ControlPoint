#include <iostream>
#include <map>
#include <string>

using namespace std;

class ControlPoint {
  public:
  ControlPoint () { }
  virtual void atControlPoint() = 0;
};

class ControlPointManager {
    public:
    static map <string, ControlPoint*> m_control_points;
    static void registerControlPoint(ControlPoint *m_obj, string control_point_name);
    static void atControlPoint(string control_point_name);
};

map <string, ControlPoint *> ControlPointManager::m_control_points;

void ControlPointManager::registerControlPoint(ControlPoint *m_obj, string control_point_name) {
	ControlPointManager::m_control_points[control_point_name] = m_obj;
}

void ControlPointManager::atControlPoint(string control_point_name) {
	ControlPoint* control_point = ControlPointManager::m_control_points[control_point_name];
	if (control_point != NULL)
		return control_point->atControlPoint();
}


class MycontrolPoint: public ControlPoint {
		public:
			virtual void atControlPoint() {
				cout <<"MycontrolPoint::atControlPoint() called." << endl;
			}
};


#define CONTROL_POINT(control_point_name)  \
    ControlPointManager::atControlPoint(control_point_name)


#define CP_NAME  "MycontrolPoint"

void application_routine( ) {

	cout<<"1"<<endl;
	CONTROL_POINT(CP_NAME);
	cout<<"if"<<endl;
}


int main()
{
    //MycontrolPoint *mobj = new MycontrolPoint();
    MycontrolPoint mobj;
    ControlPointManager::registerControlPoint(&mobj, CP_NAME);
    application_routine();
    return 0;
}
