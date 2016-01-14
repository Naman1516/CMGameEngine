﻿#ifndef HGL_GRAPH_RENDERABLE_DATA_INCLUDE
#define HGL_GRAPH_RENDERABLE_DATA_INCLUDE

#include<hgl/graph/VertexBuffer.h>
#include<hgl/graph/ColorFormat.h>
#include<hgl/graph/AABox.h>
namespace hgl
{
    namespace graph
    {
        /**
         * 可渲染对象数据
         */
        class RenderableData
        {
        protected:

            uint primitive;                                                                                                         ///<绘制的图元类型

            VertexBufferBase **vertex_buffer;                                                                                       ///<顶点数据缓冲区

            AABox BoundingBox;                                                                                                      ///<绑定盒

            ColorFormat vb_color_format;                                                                                            ///<颜色顶点属性格式

        private:

            bool                        _SetVertexBuffer     (VertexBufferType,VertexBufferBase *);                                 ///<设置顶点缓冲区数据

        public:

            RenderableData(uint prim);
            ~RenderableData();

            uint                        GetPrimitive        ()const{return primitive;}                                              ///<取得要绘制的图元类型

        public: //通用顶点缓冲区设置

            bool                        SetVertexBuffer     (VertexBufferType,VertexBufferBase *);                                  ///<设置顶点缓冲区数据
            bool                        ClearVertexBuffer   (VertexBufferType);                                                     ///<清除顶点缓冲区数据
            VertexBufferBase *          GetVertexBuffer     (VertexBufferType);                                                     ///<取得顶点缓冲区数据

        public: //顶点格式相关

            int                         GetVertexCompoment  ()const                                                                 ///<取得顶点数据成分数量
            {
                return vertex_buffer[vbtVertex]?vertex_buffer[vbtVertex]->GetComponent():0;
            }

        public: //颜色格式相关

            void                        SetVertexColorFormat(ColorFormat fmt)   {vb_color_format=fmt;}                              ///<设置顶点色属性格式
            ColorFormat                 GetVertexColorFormat()const             {return vb_color_format;}                           ///<取得顶点色属性格式

        public: //专项顶点缓冲区设置

            template<typename T>
            bool                        SetVertex           (VertexBuffer3<T> *vb)                                                  ///<设定顶点数据
            {
                if(!vb)return(false);

                Vector3f min_v,max_v,len;

                vb->GetBoundingBox(min_v,max_v);

                BoundingBox.SetMinMax(min_v,max_v);

                return SetVertexBuffer(vbtVertex,vb);
            }

            template<typename T>
            bool                        SetVertex           (VertexBuffer2<T> *vb){return SetVertexBuffer(vbtVertex,vb);}           ///<设定顶点数据

            bool                        SetIndex            (VertexBufferBase *vb){return SetVertexBuffer(vbtIndex,vb);}            ///<设置渲染数据索引
            bool                        SetColor            (VertexBufferBase *vb,ColorFormat cf)                                   ///<设置顶点颜色数据
            {
                if(!SetVertexBuffer(vbtColor,vb))
                    return(false);

                SetVertexColorFormat(cf);
                return(true);
            }
            bool                        SetNormal           (VertexBufferBase *vb){return SetVertexBuffer(vbtNormal,vb);}           ///<设置渲染顶点法线数据
            bool                        SetTangents         (VertexBufferBase *vb){return SetVertexBuffer(vbtTangent,vb);}          ///<设置渲染顶点切线数据
            bool                        SetSecondColor      (VertexBufferBase *vb){return SetVertexBuffer(vbtSecondColor,vb);}      ///<设置顶点第二颜色数据
            bool                        SetFogCoord         (VertexBufferBase *vb){return SetVertexBuffer(vbtFogCoord,vb);}         ///<设置顶点雾数据

        public: //绑定盒相关

            void                        SetBoundingBox      (const AABox &box)  {BoundingBox=box;}                                  ///<设置绑定盒
            void                        GetBoundingBox      (AABox &box)        {box=BoundingBox;}                                  ///<取得绑定盒

            const Vector3f              GetCenter           ()const                                                                 ///<取得中心点
            {
//              Vector3f result;
//
//              result.x=(BoundingBox.minPoint.x+BoundingBox.maxPoint.x)/2.0f;
//              result.y=(BoundingBox.minPoint.y+BoundingBox.maxPoint.y)/2.0f;
//              result.z=(BoundingBox.minPoint.z+BoundingBox.maxPoint.z)/2.0f;

//              return result;

                return BoundingBox.center;
            }

            void                        GetMinMaxVertex     (Vector3f &min_v,Vector3f &max_v)                                       ///<取得最小顶点和最大顶点
            {
//              min_v=POINT_TO_FLOAT3(BoundingBox.minPoint);
//              max_v=POINT_TO_FLOAT3(BoundingBox.maxPoint);
                min_v=BoundingBox.corner;
                max_v=BoundingBox.corner_max;
            }

        public:

            int                         GetDrawCount     ();                                                                        ///<取得可绘制的数据总数量
        };//class RenderableData
    }//namespace graph
}//namespace hgl
#endif//HGL_GRAPH_RENDERABLE_DATA_INCLUDE