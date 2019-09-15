// dear imgui: standalone example application for SDL2 + OpenGL
// If you are new to dear imgui, see examples/README.txt and documentation at the top of imgui.cpp.
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan graphics context creation, etc.)
// (GL3W is a helper library to access OpenGL functions since there is no standard header to access modern OpenGL functions easily. Alternatives are GLEW, Glad, etc.)
#include <iostream>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#include <SDL.h>

// About OpenGL function loaders: modern OpenGL doesn't have a standard header file and requires individual function pointers to be loaded manually.
// Helper libraries are often used for this purpose! Here we are supporting a few common ones: gl3w, glew, glad.
// You may use another loader/header of your choice (glext, glLoadGen, etc.), or chose to manually implement your own.
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
#include <GL/gl3w.h>    // Initialize with gl3wInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLEW)
#include <GL/glew.h>    // Initialize with glewInit()
#elif defined(IMGUI_IMPL_OPENGL_LOADER_GLAD)
#include <glad/glad.h>  // Initialize with gladLoadGL()
#else
#include IMGUI_IMPL_OPENGL_LOADER_CUSTOM
#endif

#include "Imgui_env.hpp"
#include "Env.hpp"

int loop_console(Env& env)
{
  bool done = false;
  std::string line;
  bool state = true;

  while (!done)
  {
    if (state){
      std::cout << "\033[1;32m-> \033[0m";
    } else {
      std::cout << "\033[1;31m-> \033[0m";
    }
    std::getline(std::cin, line);
    if (!line.compare("exit")){
      done = true;
    } else {
      std::string firstWord = line.substr(0, line.find(" "));
      if (env.map_console_func->count(firstWord) > 0)
      {
        std::string endStr = line.substr(line.find(" ") + 1, line.length());
        state = ((env.map_console_func->find(firstWord)->second)(endStr) == 0);
      } else {
        state = false;
      }
    }
  }
  return 0;
}

int loop_imgui(Imgui_env& env_imgui, Env& env)
{
  bool show_create_game_window = true;
  ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

  // Main loop
  bool done = false;
  while (!done)
  {
      // Poll and handle events (inputs, window resize, etc.)
      // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
      // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
      // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
      // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.

      SDL_Event event;
      while (SDL_PollEvent(&event))
      {
          ImGui_ImplSDL2_ProcessEvent(&event);
          if (event.type == SDL_QUIT)
              done = true;
          if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(env_imgui.window))
              done = true;
      }

      // Start the Dear ImGui frame
      ImGui_ImplOpenGL3_NewFrame();
      ImGui_ImplSDL2_NewFrame(env_imgui.window);
      ImGui::NewFrame();



      if (show_create_game_window)
      {
          ImGui::Begin("Another Window", &show_create_game_window, ImGuiWindowFlags_MenuBar);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)

          if (ImGui::BeginMenuBar())
          {
              if (ImGui::BeginMenu("File"))
              {
                  if (ImGui::MenuItem("Close", "Ctrl+W"))
                  {
                    done = true;
                  }
                  ImGui::EndMenu();
              }
              ImGui::EndMenuBar();
          }

          ImGui::Text("Hello from another window!");
          ImGui::End();
      }

      // Rendering
      ImGui::Render();
      glViewport(0, 0, (int)env_imgui.io->DisplaySize.x, (int)env_imgui.io->DisplaySize.y);
      glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
      glClear(GL_COLOR_BUFFER_BIT);
      ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
      SDL_GL_SwapWindow(env_imgui.window);
  }

  // Cleanup
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(env_imgui.gl_context);
  SDL_DestroyWindow(env_imgui.window);
  SDL_Quit();
  return 0;
}

// Main code
int main(int argc, char** argv)
{
  bool console_mode = false;

  if (argc > 1)
  {
    if (strcmp(argv[1], "--console") == 0 || strcmp(argv[1], "-c") == 0) {
      console_mode = true;
    }
  }

  Env& env = *(new Env());

  if (console_mode)
  {
    loop_console(env);
  } else {
    Imgui_env& env_imgui = *(new Imgui_env());
    loop_imgui(env_imgui, env);
  }

}
