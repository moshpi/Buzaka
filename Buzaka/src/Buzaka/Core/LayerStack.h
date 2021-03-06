#pragma once

#include "pch/bzpch.h"
#include "Layer.h"

namespace Buzaka {

    class LayerStack {
    public:
        ~LayerStack();

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);
        void PopLayer(Layer* layer);
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_LayerStack.begin(); }
        std::vector<Layer*>::iterator end() { return m_LayerStack.end(); }
        std::vector<Layer*>::reverse_iterator rbegin() { return m_LayerStack.rbegin(); }
        std::vector<Layer*>::reverse_iterator rend() { return m_LayerStack.rend(); }

    private:
        std::vector<Layer*> m_LayerStack;
        unsigned int m_LayerInsertToIndex = 0;
    };

}
