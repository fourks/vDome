#pragma once
#include "ofMain.h"
#include "projector.h"
#include "model.h"
#include "input.h"
#include "window.h"

namespace vd {

class Item {
public:
    string str;
    bool isParent;
    Item(string s){
        str = s;
        isParent = false;
    }
    Item(string s, bool p){
        str = s;
        isParent = p;
    }
};
    
class Menu {
public:
    Menu();
        
    // draw methods
 	void draw(int i);
    void drawMain(int i);
    void drawInput();
    
    void drawProjector(int i);
    void drawFPS(int i);
    void drawHighlight();
    void drawBackground();
    void drawSaved();
    void drawActive(int i);
    void drawWarp(int i);
    
    // navigation
    void select();
    void back();
    void setEditMode();
    
    // mouse methods
    void mousePressed(ofMouseEventArgs& mouseArgs);
    void mouseDragged(ofMouseEventArgs& mouseArgs);
    void mouseReleased(ofMouseEventArgs& mouseArgs);
    
    // keyboard methods
    void keyPressed(int key);
    void keyReleased(int key);
    
    // utils
    void toggle();
    float roundTo(float val, float n);
    // state
    int frameCnt;
    bool saved;
    bool active;
    int pActive;

    struct MenuItem {
        int currentItem;
        vector<Item*> items;
        int menuId;
        MenuItem **parent;
    };
    
    // menus
    MenuItem *menuMain;
    MenuItem *menuInput;
    MenuItem *menuInputVideo;
    MenuItem *menuInputTransform;
    MenuItem *menuWarp;
    MenuItem *menuBlend;
    MenuItem *menuLevels;
    MenuItem *menuBrush;
    MenuItem *menuColor;
    MenuItem *menuHSL;
    MenuItem *menuGamma;
    MenuItem *menuSetup;
    MenuItem *menuPosition;
    MenuItem *menuOrientation;
    MenuItem *menuFov;
    MenuItem *menuLens;
    MenuItem *menuScale;
    MenuItem *menuShear;
    MenuItem **currentMenu;

    enum menus {MAIN, INPUT, INPUT_VIDEO, INPUT_TRANSFORM, WARP, BLEND, COLOR, HSL, GAMMA, SETUP,
                POSITION, ORIENTATION, FIELD_OF_VIEW, LENS, SHEAR, SCALE, BRUSH, LEVELS};

    // menu items
    enum inputItems {SOURCE, FORMAT, LOOP, ENABLE, TRANSFORM};
    enum intputTransformItems {INPUT_FLIP, INPUT_ROTATE, INPUT_TILT, INPUT_SCALE};

    enum warpItems  {CORNERPIN, GRID};
    enum blendItems {BRIGHTNESS, CONTRAST, B_LEVELS, B_BRUSH};
    enum levelsItems{BLACK, WHITE};
    enum brushItems {BRUSH_SCALE, BRUSH_OPACITY};
    enum colorItems {COLOR_HSL, COLOR_GAMMA};
    enum hslItems   {HUE, SATURATION, LIGHTNESS};
    enum gammaItems {GAMMA_RGB, GAMMA_R, GAMMA_G, GAMMA_B};
    enum posItems   {AZIMUTH, ELEVATION, DISTANCE};
    enum orienItems {TILT, ROLL, PAN};
    enum fovItems   {FOV};
    enum lensItems  {OFFSET_X, OFFSET_Y};
    enum scaleItems {SCALE_X, SCALE_Y};
    enum shearItems {SHEAR_YZ, SHEAR_ZX, SHEAR_XZ,
                     SHEAR_ZY, SHEAR_YX, SHEAR_XY};

    void findEdit(int mode);

    // layout
    int px;
    int py;
    int pw;
    int ph;
    int padx;
    int pady;

    // keyboard
    bool all;
    int cKey;

    // value
    float value;
    float orgValue;
    float ctrlValue;
    float altValue;

    // pointers
    Model *model;
    Input *input;
    vector<Window> *windows;
    vector<Projector> *projectors;
    ofxMultiGLFWWindow *glfw;

    bool autosave;
};

}
