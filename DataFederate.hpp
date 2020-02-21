#ifndef DATAFEDERATE_HPP
#define DATAFEDERATE_HPP 1

#include <unordered_set>
#include "DataAttribute.hpp"

namespace UPIM{
	namespace DATA{
//Data structure for ordinary Federate
		class DataFederate{
		public:

//Default constructor
			DataFederate() noexcept;

//Full-gapes lvalue constructor
            DataFederate(const QString& name, const QString& type,const QString& semantic="") noexcept;

//Full-gapes rvalue constructor
            DataFederate(QString&& name, QString&& type, QString&& semantic = "") noexcept;

//Copy constructor
            DataFederate(const DataFederate&) = delete;

//Move constructor
            DataFederate(DataFederate&&) = default;

//Copy assigment operator
            DataFederate& operator=(const DataFederate&) = delete;

//Move assigment operator
            DataFederate& operator=(DataFederate&&) = default;

//Init lvalue set of federate attributes
            void SetAttributes(const std::unordered_set<DataAttribute,DataAttributeHash>& attributes) noexcept;

//Init lvalue set of federate parameters
            void SetParameters(const std::unordered_set<QString>& parameters) noexcept;

//Init rvalue set of federate attributes
            void SetAttributes(std::unordered_set<DataAttribute,DataAttributeHash>&& attributes) noexcept;

//Init rvalue set of federate parameters
            void SetParameters(std::unordered_set<QString>&& parameters) noexcept;

//Add lvalue attribute to the federate set
            void AddAttribute(const DataAttribute& attr) noexcept;

//Add rvalue attribute to the federate set
            void AddAttribute(DataAttribute&& attr) noexcept;

//Get federate name
            QString GetName() const noexcept;

//Get federate type
            QString GetType() const noexcept;

//Get other info about federate
            QString GetSemantic() const noexcept;

//Get set of Attributes to change
            std::unordered_set<DataAttribute,DataAttributeHash>& GetAttributes() noexcept;

//Get set of Attributes const
            const std::unordered_set<DataAttribute,DataAttributeHash>& GetAttributes() const noexcept;

//Get Hash of Attributes set
            size_t GetAttributeHash() const noexcept;

		private:

//Federate name
            QString _name;
//Federate type
            QString _type;
//Other information about federate
            QString _semantic;
//Set of Federate's Attributes
            std::unordered_set<DataAttribute,DataAttributeHash> _attributes;
//Set of Federate's Parameters
            std::unordered_set<std::wstring> _parameters;
		};

//Hasher for federate
		struct DataFederateHash{
            size_t operator()(const DataFederate& fed) const;
		};

//Equality operator to federates
		bool operator==(const DataFederate& lhs, const DataFederate& rhs);
}
}


#endif
