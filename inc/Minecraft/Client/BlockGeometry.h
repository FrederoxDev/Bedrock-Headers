#pragma once

#include <array>
#include <vector>
#include <glm/vec3.hpp>
#include <string>

#include "Minecraft/Util/AABB.h"
#include "Minecraft/Util/Facing.h"

namespace BlockGeometry {
    struct Face {
        float u0;
        float v0;
        float u1;
        float v1;
        int rotation;
        std::string texture;
        int textureIndex;
        bool enabled;

        Face();
        void setUV(float, float, float, float);
    };

    class AlignedFace {
    public:
        std::array<Vec3, 4> verts;
        std::array<Vec2, 4> uvs;
        size_t textureIndex;

        AlignedFace(const std::array<Vec3, 4>&, const std::array<Vec2, 4>&, size_t);
    };

    class OrientedFace {
    public:
        std::array<Vec3, 4> verts;
        std::array<Vec2, 4> uvs;
        Vec3 norm;
        size_t textureIndex;

        OrientedFace(const std::array<Vec3, 4>&, const std::array<Vec2, 4>&, const Vec3&, size_t);
    };

    typedef std::vector<OrientedFace> OrientedFaceVector;

    class Model;
    class Rotation;

    class TessellatedModel {
    public:
        struct Occlusion {
            std::array<unsigned char, 8> blocking;
            std::array<unsigned char, 8> visible;
        };

        std::array<AABB, 4> mAABoxes;
        std::array<std::vector<AlignedFace>, 6> mEdgeSet;
        std::array<std::vector<AlignedFace>, 6> mAlignedSet;
        OrientedFaceVector mOrientedSet;
        std::array<Occlusion, 6> mOcclusion;
        std::array<Occlusion, 3> mTopOcclusionRot;
        std::array<Occlusion, 3> mBotOcclusionRot;
        std::vector<std::string> mTextureNames;

        TessellatedModel();
        void clear();
        void createFromBlockModel(const Model&, const Rotation&);
        void addCube(const AABB&, const glm::vec3&, const glm::vec3&, const Rotation&, const std::array<Face, 6>&);
        void buildOcclusionData();
    private:
        void _addFace(const AABB&, const glm::vec3&, const glm::vec3&, const Rotation&, const Face&, unsigned char);
    };
}