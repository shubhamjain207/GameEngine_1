#pragma once

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<fstream>
#include<iostream>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Mesh.h"
#include "Vertex.h"


class Primitive {

private:
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;
public:
	Primitive() {}
	virtual ~Primitive() {}

	void set(const Vertex* vertices, const GLuint noOfVertices, const GLuint* indices, const GLuint noOfIndices) {
	
		for (size_t i = 0; i < noOfVertices; i++) {
			this->vertices.push_back(vertices[i]);

		}

		for (size_t i = 0; i < noOfIndices; i++) {
			this->indices.push_back(indices[i]);

		}
	

	}

	inline Vertex* getVertices() { return this->vertices.data(); };
	inline GLuint* getIndices() { return this->indices.data(); };
	inline const unsigned getNoOfVertices() { return this->vertices.size();}
	inline const unsigned getNoOfIndices() { return this->indices.size(); }


};

class Quad : public Primitive {
	
public:
	Quad()
		:Primitive()
	{
		/*Vertex vertices[] = {

		glm::vec3(-0.5f,   -0.5f, 0.0f), glm::vec3(1.f, 0.0f,1.0f),   glm::vec2(-0.5f,-0.5f),glm::vec3(0.f, 0.0f,1.0f),
		glm::vec3(0.5f,   -0.5f, 0.0f),     glm::vec3(1.f, 0.0f,0.0f),   glm::vec2(0.5f,   -0.5f), glm::vec3(0.f, 0.0f,1.0f),
		glm::vec3(0.0f,  0.5f, 0.0f),    glm::vec3(1.f, 0.0f,0.0f),    glm::vec2(0.0f,  0.5f), glm::vec3(0.f, 0.0f,1.0f)

		};*/

		Vertex vertices[] = {

		glm::vec3(-0.5f,   -0.5f, 0.0f), glm::vec3(1.f, 0.0f,1.0f),  
		glm::vec3(0.5f,   -0.5f, 0.0f),     glm::vec3(1.f, 0.0f,0.0f),   
		glm::vec3(0.0f,  0.5f, 0.0f),    glm::vec3(1.f, 0.0f,0.0f),    


		};

		unsigned noOfVertices = sizeof(vertices) / sizeof(Vertex);

		GLuint indices[] = {

			0,1,2

		};

		unsigned noOfIndices = sizeof(indices) / sizeof(unsigned int);

		this->set(vertices, noOfVertices, indices, noOfIndices);


	}
	

};