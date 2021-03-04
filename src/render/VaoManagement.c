#include <render/OpenGL.h>

#include <GL/glew.h>

Model loadToVao(LoadableData* data)
{
    Model model;
    glGenVertexArrays(1, &model.vao);

    glBindVertexArray(model.vao);

    glGenBuffers(1, &model.vertexVbo);
    glBindBuffer(GL_ARRAY_BUFFER, model.vertexVbo);
    glBufferData(GL_ARRAY_BUFFER, data->vertexCount, data->vertex, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindBuffer(GL_ARRAY_BUFFER, NO_GL_OBJECT);

    glGenBuffers(1, &model.normalVbo);
    glBindBuffer(GL_ARRAY_BUFFER, model.normalVbo);
    glBufferData(GL_ARRAY_BUFFER, data->normalCount, data->normal, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glBindBuffer(GL_ARRAY_BUFFER, NO_GL_OBJECT);

    glGenBuffers(1, &model.ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, model.ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->indexCount, data->index, GL_STATIC_DRAW);
    glBindVertexArray(NO_GL_OBJECT);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NO_GL_OBJECT);

    model.vertexCount = data->indexCount/sizeof(int);
    return model;
}

void renderModel(Model* model)
{
    glBindVertexArray(model->vao);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    glDrawElements(GL_TRIANGLES, model->vertexCount, GL_UNSIGNED_INT, NULL);

    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(0);
    glBindVertexArray(NO_GL_OBJECT);
}

void deleteModel(Model* model)
{
    glDeleteVertexArrays(1, &model->vao);
    glDeleteBuffers(1, &model->vertexVbo);
    glDeleteBuffers(1, &model->normalVbo);
    glDeleteBuffers(1, &model->ebo);
}
