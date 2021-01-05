#include "things/ingredients/scenerunner.h"
#include "things/sceneblur.h"
#include "things/scenedeferred.h"
#include "things/sceneedge.h"
#include "things/scenegamma.h"
#include "things/scenemsaa.h"
#include "things/scenetonemap.h"
#include "things/scenehdrbloom.h"
#include "things/sceneoit.h"

std::map<std::string, std::string> sceneInfo = {
        {"blur",      "Gaussian blur"},
        {"deferred",  "deferred rendering"},
        {"edge",      "edge detection filter"},
        {"gamma",     "gamma correction"},
        {"msaa",      "multisample anti-aliasing"},
        {"tone-map",  "tone mapping example."},
        {"hdr-bloom", "bloom example with HDR tone mapping."},
        {"oit",       "order independent transparency (requires OpenGL 4.3)"}
};


int main(int argc, char *argv[]) {
    //std::string recipe = SceneRunner::parseCLArgs(argc, argv, sceneInfo);

    std::string recipe = "edge";

    SceneRunner runner("Chapter 5 - " + recipe, 800, 600, 8);
    std::unique_ptr<Scene> scene;
    if (recipe == "blur") {
        scene = std::unique_ptr<Scene>(new SceneBlur());
    } else if (recipe == "deferred") {
        scene = std::unique_ptr<Scene>(new SceneDeferred());
    } else if (recipe == "edge") {
        scene = std::unique_ptr<Scene>(new SceneEdge());
    } else if (recipe == "gamma") {
        scene = std::unique_ptr<Scene>(new SceneGamma());
    } else if (recipe == "msaa") {
        //did not work
        scene = std::unique_ptr<Scene>(new SceneMsaa());
    } else if (recipe == "tone-map") {
        scene = std::unique_ptr<Scene>(new SceneToneMap());
    } else if (recipe == "hdr-bloom") {
        scene = std::unique_ptr<Scene>(new SceneHdrBloom());
    } else if (recipe == "oit") {
        scene = std::unique_ptr<Scene>( new SceneOit() );
//#ifdef __APPLE__
//        printf("OIT example is not supported on MacOS.\n");
//        exit(EXIT_FAILURE);
//#else
//#endif
    } else {
        printf("Unknown recipe: %s\n", recipe.c_str());
        exit(EXIT_FAILURE);
    }

    return runner.run(*scene);
}
