
	size_t repeatedCount{0};
	while(m_repeated.size() != 0){
		valueType repNumber = m_repeated[m_repeated.size()-1].first;
		std::vector<valueType> curSize;
		size_t stepCounts{0};
		while(m_repeated[m_repeated.size()-1].first == repNumber){
			//std::cout << "WHILED" << std::endl;
			++stepCounts;
			size_t curr = currentCount(m_repeated[m_repeated.size()-1].second);
			std::cout << "*** __ curr = " << curr << std::endl; 
			//std::cout << "cur = " << curr << ", stepCounts = " << stepCounts << std::endl;
			if(length.size() == repeatedCount){
				std::cout << "Pushed : " << m_repeated[m_repeated.size()-1].first << " " << m_repeated[m_repeated.size()-1].second << " : " << stepCounts + curr << std::endl;
				length.push_back(std::make_pair(m_repeated[m_repeated.size()-1], stepCounts + curr));
			}else{
				if(stepCounts + curr > length[repeatedCount].first.second){
					std::cout << "stepCounts = " << stepCounts << ", curr = " << curr << " > " << length[repeatedCount].first.second << std::endl;
					length.pop_back();
					length.push_back(std::make_pair(m_repeated[m_repeated.size()-1], stepCounts + curr));
				}
			}
			m_repeated.pop_back();
			stepCounts = 0;
		}
		++repeatedCount;
	}
	size_t rep{0};
	while(m_repeated.size() != 0){
		valueType repNumber = m_repeated[m_repeated.size()-1].first;
		std::vector<valueType> curSize;
		size_t stepCounts{0};
		while(m_repeated[m_repeated.size()-1].first == repNumber){
			//std::cout << "WHILED" << std::endl;
			++stepCounts;
			size_t curr = currentCount(m_repeated[m_repeated.size()-1].second);
			//std::cout << "cur = " << curr << ", stepCounts = " << stepCounts << std::endl;
			if(length.size() > rep && curr + stepCounts > length[rep+1].first.second){
				length.pop_back();
				length.push_back(std::make_pair(m_repeated[m_repeated.size()-1], stepCounts + curr));	
			}else{
				length.push_back(std::make_pair(m_repeated[m_repeated.size()-1], stepCounts + curr));
			}
			m_repeated.pop_back();
			stepCounts = 0;
		}
		++rep;
	}
