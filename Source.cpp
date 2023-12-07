//#include<glad/glad.h>
//#include <GLFW/glfw3.h>
//#include<fstream>
//#include<iostream>
//#include <string>
//
//#include "glm/glm.hpp"
//#include "glm/gtc/matrix_transform.hpp"
//#include "glm/gtc/type_ptr.hpp"
//#include "Shader.h"
//#include "Texture.h"
//#include "Material.h"
//#include "Mesh.h"
//#include "Vertex.h"
//#include "Primitives.h"
//
//
//
//float posX = 0.0f, posY = 0.0f, posZ = 4.0f;
//float count = 0;
//float _count = 0.02;
//
//float _radius = 40.0f;
//
//float rotOnY = 0.0f;
//
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    glViewport(0, 0, width, height);
//}
//void processInput(GLFWwindow* window, Mesh& mesh) {
//
//
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
//		glfwSetWindowShouldClose(window, true);
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
//		
//		mesh.move(glm::vec3(0.0f, 0.0f, -0.4f));
//
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
//	
//		mesh.move(glm::vec3(-0.01f, 0.0f, 0.0f));
//
//
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
//		
//		mesh.move(glm::vec3(0.0f, 0.0f, 0.4f));
//
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
//		
//		mesh.move(glm::vec3(0.01f, 0.0f, 0.0f));
//	
//	}
//
//
//	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
//		
//		mesh.rotate(glm::vec3(0.0f, 0.0f, 4.0f));
//	
//	}
//
//
//	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
//		
//		mesh.rotate(glm::vec3(0.0f, 0.0f, -4.0f));
//	
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
//	
//		mesh.rotate(glm::vec3(0.0f, -4.0f, 0.0f));
//
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
//	
//		mesh.rotate(glm::vec3(0.0f, 4.0f, 0.0f));
//	
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//		
//		mesh.rotate(glm::vec3(4.0f, 0.0f, 0.0f));
//		
//	}
//
//	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//		
//		mesh.rotate(glm::vec3(4.0f, 0.0f, 0.0f));
//		
//	}
//
//
//	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
//
//
//
//	}
//
//}
//
//
//
//int main(void)
//{
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//    GLFWwindow* window;
//
//    if (!glfwInit())
//        return -1;
//
//
//
//    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//    if (!window)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
//
//        return -1;
//
//    }
//
//
//
//    glViewport(0, 0, 800, 600);
//
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    Texture tex = Texture("container.jpg", GL_TEXTURE_2D,0);
//
//	
//
//    Material material(glm::vec3(1.0f), glm::vec3(0.f), glm::vec3(10.f), tex.getTextureUnit());
//
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//
//    Shader coreProgram("vertex.glsl", "fragment.glsl");
//    coreProgram.use();
//
//  
//
//    Mesh mesh(&Quad(), glm::vec3(0.0f), glm::vec3(1.f), glm::vec3(1.f));
//
//	glm::mat4 ProjectionMatrix = glm::perspective(glm::radians(10.0f), 800.0f / 600.0f, 0.1f, 100.0f);
//	GLint projectionMatrix = glGetUniformLocation(coreProgram.getId(), "ProjectionMatrix");
//	glUniformMatrix4fv(projectionMatrix, 1, GL_FALSE, glm::value_ptr(ProjectionMatrix));
//
//    while (!glfwWindowShouldClose(window))
//    {
//		processInput(window, mesh);
//
//        glClearColor(0.0f / 255.f, 0.0f / 255.f, 0.0f / 255.f, 1);
//        glEnable(GL_DEPTH_TEST);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//
//        coreProgram.use();
//
//		const float radius1 = _radius;
//		float camX = static_cast<float>(sin(count) * 40.0f);
//		float camZ = static_cast<float>(cos(count) * radius1);
//
//		glm::mat4 ViewMatrix = glm::mat4(1.0f);
//		ViewMatrix = glm::lookAt(glm::vec3(camX, 1.0f, camZ), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
//		coreProgram.setMat4fv(ViewMatrix, "ViewMatrix");
//
//
//
//		material.sendToShader(coreProgram);
//
//
//		glm::vec3 lightPos = glm::vec3(0.0f, 0.0f, -1.f);
//		coreProgram.set3fv(lightPos, "LightPos");
//
//		glm::vec3 color2 = glm::vec3(1.0f, 1.0f, 1.f);
//		coreProgram.set3fv(color2, "ColorChange");
//
//
//		glm::vec3 pos = glm::vec3(camX, 0.0f, camZ);
//		coreProgram.set3fv(pos, "cameraPos");
//
//		tex.bind();
//		mesh.render(&coreProgram);
//
//        glfwSwapBuffers(window);
//
//        glfwPollEvents();
//    }
//
//    glfwTerminate();
//    return 0;
//}
