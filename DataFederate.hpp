#ifndef DATAFEDERATE_HPP
#define DATAFEDERATE_HPP 1

#include <boost/variant.hpp>
#include <boost/optional.hpp>

#include <unordered_set>

#include "DataAttribute.hpp"

namespace UPIM{
	namespace DATA{
		class DataAttribute;

		class DataFederate{
		public:

			DataFederate() noexcept;

            DataFederate(const QString& name, const QString& type,const QString& semantic="") noexcept;

            DataFederate(QString&& name, QString&& type, QString&& semantic = "") noexcept;

			void SetAttributes(const std::unordered_set<DataAttribute,DataAttributeHash>& attributes) noexcept;

            void SetParameters(const std::unordered_set<QString>& parameters) noexcept;

			void AddAttribute(const DataAttribute& attr) noexcept;

			void AddAttribute(DataAttribute&& attr) noexcept;

			void SetAttributes(std::unordered_set<DataAttribute,DataAttributeHash>&& attributes) noexcept;

            void SetParameters(std::unordered_set<QString>&& parameters) noexcept;

            QString GetName() const noexcept;

            QString GetType() const noexcept;

            QString GetSemantic() const noexcept;

			std::unordered_set<DataAttribute,DataAttributeHash>& GetAttributes() noexcept;

			size_t GetAttributeHash() const noexcept;

			const std::unordered_set<DataAttribute,DataAttributeHash>& GetAttributes() const noexcept;

    //	std::unordered_set<QString>& GetParametersMap() const;

		private:
            QString _name;
            QString _type;
            QString _semantic;
			std::unordered_set<DataAttribute,DataAttributeHash> _attributes;
            std::unordered_set<std::wstring> _parameters;
		};

		struct DataFederateHash{
			size_t operator()(const DataFederate& fed) const;
		};

		bool operator==(const DataFederate& lhs, const DataFederate& rhs);
}
}


#endif
