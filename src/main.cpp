extern "C" {
    #include <raylib.h>
}
#include<iostream>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Anatoly Karpova!!!");

    Camera camera = { { -4.61976f, 13.6449f, 18.5167f }, { -4.61976f, -10.677f, -1.38298f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0};

    Image image = LoadImage("../map/map_switch.png");
    Texture2D cubicmap = LoadTextureFromImage(image);

    Mesh mesh = GenMeshCubicmap(image, (Vector3){ 1.0f, 1.0f, 1.0f });
    Model model = LoadModelFromMesh(mesh);

    Texture2D texture = LoadTexture("../map/textur_2.png");
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

    Vector3 mapPosition = { -14.0f, -5.0f, -3.0f };
    Vector3 cubePosition = { 1.0f, -4.5f, 0.0f };
    UnloadImage(image);

    SetCameraMode(camera, CAMERA_FREE);
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);

            BeginMode3D(camera);

                DrawModel(model, mapPosition, 1.0f, WHITE);

                DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, RED);
                DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, BLACK);

            EndMode3D();

            DrawTextureEx(cubicmap, (Vector2){ screenWidth - cubicmap.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
            DrawRectangleLines(screenWidth - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);
            DrawText("SCORE", 658, 90, 10, RED);
            DrawText("LIFE", 658, 104, 10, RED);
            DrawFPS(10, 10);

        if (IsKeyDown(KEY_RIGHT)) cubePosition.x += 0.2f;
        else if (IsKeyDown(KEY_LEFT)) cubePosition.x -= 0.2f;
        else if (IsKeyDown(KEY_DOWN)) cubePosition.z += 0.2f;
        else if (IsKeyDown(KEY_UP)) cubePosition.z -= 0.2f;
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    //--------------------------------------------------------------------------------------
    UnloadTexture(cubicmap);
    UnloadTexture(texture);
    UnloadModel(model);

    CloseWindow();
    //--------------------------------------------------------------------------------------

    return 0;
}
