#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// 콜백 및 입력 함수 선언
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// 파일에서 셰이더 소스 코드를 읽어오는 함수

const unsigned int SCR_WIDTH = 1024;
const unsigned int SCR_HEIGHT = 800;

int main()
{
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Window", NULL, NULL);

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // GLAD 초기화
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    

    glDrawArrays(GL_TRIANGLES, 0 , 3);
    while (!glfwWindowShouldClose(window))
    {
        // 입력 처리
        processInput(window);


        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}

// 입력 처리 함수: ESC 키를 누르면 윈도우 종료
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// 프레임버퍼 크기 변경 콜백 함수
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}