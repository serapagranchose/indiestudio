/*
** EPITECH PROJECT, 2019
** game.cpp
** File description:
** game
*/

#include "indiestudio.hpp"

int setdown(Game *bomberman)
{
    UnloadTexture(bomberman->map.flat_map);
    //UnloadTexture(bomberman->map.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture);
    //UnloadModel(bomberman->map.model);

    printf("player nb:%ld\n", bomberman->players.size());
    printf("game_status:%d\n", bomberman->status);
    printf("position:\nx:%.2f y:%.2f z:%.2f\n\n", bomberman->camera.position.x, bomberman->camera.position.y, bomberman->camera.position.z); // Camera position
    printf("target:\nx:%.2f y:%.2f z:%.2f\n\n", bomberman->camera.target.x, bomberman->camera.target.y, bomberman->camera.target.z);      // Camera looking at point
    printf("up:\nx:%.2f y:%.2f z:%.2f\n\n", bomberman->camera.up.x, bomberman->camera.up.y, bomberman->camera.up.z);          // Camera up vector (rotation towards target)
    printf("fovy:\t%.2f\n\n", bomberman->camera.fovy);                               // Camera field-of-view Y
    printf("type:\t%d\n", bomberman->camera.projection);

    while (!bomberman->players.empty())
        bomberman->players.pop_back();

    CloseWindow();

    return (0);
}

int game_loop(Game *bomberman)
{
    while (!WindowShouldClose())
    {
        UpdateCamera(&bomberman->camera);

        game_input(bomberman);

//draw(bomberman); is a segfault cause
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(bomberman->camera);
        draw3d(bomberman);
        EndMode3D();
        draw2d(bomberman);
        EndDrawing();
    }
    return (0);
}

int setup(Game *bomberman)
{
    srand(time(NULL));
    InitWindow(bomberman->window.screen_width, bomberman->window.screen_height, "Anatoly Karpov!!!");
    SetTargetFPS(60);

/*
    Image image = LoadImage("../map/switch.png");
    bomberman->map.flat_map = LoadTextureFromImage(image);
    Mesh mesh = GenMeshCubicmap(image, (Vector3){1.0f, 1.0f, 1.0f});
    UnloadImage(image);
    bomberman->map.model = LoadModelFromMesh(mesh);
    Texture2D texture = LoadTexture("../texture/playfield.png");
    bomberman->map.model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;
    bomberman->map.position = {0.0f, 0.0f, 0.0f};
*/
    Button play;
    play.status = 0;
    play.texture = LoadTexture("../button/play.png");
    float frameHeight = (float)play.texture.height / 3;
    play.bounds = {0, 0, (float)play.texture.width, frameHeight};
    bomberman->buttons.push_back(play);

    bomberman->camera.position = (Vector3){0.0f, 10.0f, 10.0f};
    bomberman->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    bomberman->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    bomberman->camera.fovy = 45.0f;
    bomberman->camera.projection = CAMERA_PERSPECTIVE;
//    SetCameraMode(bomberman->camera, CAMERA_FREE);

    return (0);
}
