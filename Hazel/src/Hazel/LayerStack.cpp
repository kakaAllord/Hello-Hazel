#include "hzpch.h"
#include "LayerStack.h"


namespace Hazel
{
	LayerStack::LayerStack() 
	{
		m_OverlayBegin = m_Layers.begin();
	}

	LayerStack::~LayerStack() 
	{
		for ( Layer* layer : m_Layers)
			delete layer;
	}
	
	void LayerStack::PushLayer(Layer* layer)
	{
		m_OverlayBegin = m_Layers.emplace(m_OverlayBegin, layer);
		++m_OverlayBegin;
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_OverlayBegin, layer);

		if (it != m_OverlayBegin)
		{
			const auto offset = std::distance(m_Layers.begin(), m_OverlayBegin);

			m_Layers.erase(it);

			m_OverlayBegin = m_Layers.begin() + ( offset - 1 );
		}
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
		overlay->OnAttach();

	}

	void LayerStack::PopOverlay(Layer* overlay)
	{

		auto it = std::find(m_OverlayBegin, m_Layers.end(), overlay);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}