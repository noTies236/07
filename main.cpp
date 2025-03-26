#include <glm/vec3.hpp>						// glm::vec3
#include <glm/vec4.hpp>						// glm::vec4
#include <glm/mat4x4.hpp>					// glm::mat4
#include <glm/ext/matrix_transform.hpp>		// glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp>	// glm::perspective
#include <glm/ext/scalar_constants.hpp>		// glm::pi
#define	 GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>
#include <iostream>
#include "vector"

/* Note: Estrutura Interna de glm::mat4 Quando você cria uma glm::mat4 em C++ (como em glm::mat4 matrix(1.0f);), 
internamente ela é implementada como uma coleção de 4 glm::vec4. Cada glm::vec4 é um vetor de 4 componentes 
(x, y, z, w), e a matriz mat4 é basicamente um conjunto de 4 desses vetores, representando as 4 linhas da matriz.*/

void printMatrix(const glm::mat4& matrix);
void AngleOfTowVector(const glm::vec3& v1, const glm::vec3& v2);

void AngleOfTowVector(const glm::vec3& v1, const glm::vec3& v2)
{
	std::cout << "\n\nAngleOfTowVector: " << glm::to_string(v1) << "\n";
	std::cout << "AngleOfTowVector: " << glm::to_string(v2) << "\n";
	
	// Você está obtendo o cosseno do ângulo entre os vetores v1 e v2.
	std::cout << "DOT vec1 n vec2: " << glm::dot(v1, v2) << "\n";
	std::cout << "acos: " << std::acos(glm::dot(v1, v2)) * 180.0 / 3.14159265358979323846 << "\n";
}

void printMatrix(const glm::mat4& matrix)
{
	// [ X  Y  Z  W ]
	// [ 1, 0, 0, 0 ]
	// [ 0, 1, 0, 0 ]
	// [ 0, 0, 1, 0 ]
	// [ 0, 0, 0, 1 ]

	for (int row = 0; row <= 3; row++) {
		std::cout << "matrix " << glm::to_string(matrix[row]) << "\n";
	}
}

int main()
{         
	/* create a 'vertex' (i.e point 
	this is the local coordinates
	1.0f at the end is the 'w' coordinate
	w=1 means we have a position*/
								// if w=0 means we have direction. point w=1; vector w=0;
	glm::vec4 vertex(1.0f, 5.0f, 1.0f, 1.0f); 
	std::cout << "vertex: " << glm::to_string(vertex) << "\n";
	
	/*create a model matrix for our geometry 
	initialize with '1' for identify matrix. NOTE: Do not 
	count on glm to provide you an identity matrix*/
	glm::mat4 model(1.0f);
	printMatrix(model);

	// scaling matrix
	model = glm::scale(glm::mat4(1.0f), glm::vec3(3.0f, 2.0f, 2.0f));
	printMatrix(model);

	glm::mat4 model_rotate(1.0f);
	model_rotate = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0, 1, 0));

	std::cout << "rotate\n";
	printMatrix(model_rotate);
	std::cout << "\n";

	// now apply our  model  matrix to the vertex
	glm::vec4 wordpace_vertex = (model * vertex);
	std::cout << "our vertex in world space\n";
	std::cout << glm::to_string(wordpace_vertex);

	//std::cout << "dot - Angle: " << << "\n";
	AngleOfTowVector({ 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f });
	
	return 0;
} 