#include "DataFederate.hpp"
#include <algorithm>
namespace UPIM{
	namespace DATA{

		using namespace std;

		DataFederate::DataFederate() noexcept{}

        DataFederate::DataFederate(const QString& name, const QString& type,const QString& semantic) noexcept:
					_name(name), _type(type), _semantic(semantic) {}

        DataFederate::DataFederate(QString&& name, QString&& type, QString&& semantic) noexcept:
					_name(move(name)), _type(move(type)), _semantic(move(semantic)) {}

        void DataFederate::SetAttributes(const unordered_set<DataAttribute,DataAttributeHash>& attributes) noexcept{
			_attributes = attributes;
		}

        void DataFederate::AddAttribute(const DataAttribute& attr) noexcept{
            _attributes.insert(attr);
        }

        void DataFederate::AddAttribute(DataAttribute&& attr) noexcept{
            _attributes.insert(move(attr));
		}

        void DataFederate::SetParameters(const unordered_set<QString>& parameters) noexcept{
            //_parameters = parameters;
		}

        void DataFederate::SetAttributes(unordered_set<DataAttribute,DataAttributeHash>&& attributes) noexcept{
			_attributes = move(attributes);
		}

        void DataFederate::SetParameters(unordered_set<QString>&& parameters) noexcept{
            //_parameters = move(parameters);
		}

        QString DataFederate::GetName() const noexcept{return _name;}

        QString DataFederate::GetType() const noexcept{return _type;}

        QString DataFederate::GetSemantic() const noexcept{return _semantic;}

        unordered_set<DataAttribute,DataAttributeHash>& DataFederate::GetAttributes() noexcept {return _attributes;}

        const unordered_set<DataAttribute,DataAttributeHash>& DataFederate::GetAttributes() const noexcept {return _attributes;}

		size_t DataFederate::GetAttributeHash() const noexcept{
			size_t res = 0;
			DataAttributeHash hash;
			for(const auto&x:_attributes){
				res+=hash(x);
			}
			return res%_attributes.max_bucket_count();
		}

        size_t DataFederateHash::operator ()(const DataFederate& fed) const{
            size_t h1 = qHash(fed.GetName());
            size_t h2 = qHash(fed.GetType());
            size_t h3 = qHash(fed.GetSemantic());
            size_t h4 = fed.GetAttributeHash();
            return h3+h2*211+h4*211*211+h1*211*211*211;
		}

		bool operator==(const DataFederate& lhs, const DataFederate& rhs){
			return lhs.GetName() == rhs.GetName() && lhs.GetType() == rhs.GetType() && lhs.GetSemantic() == rhs.GetSemantic() && lhs.GetAttributes() == rhs.GetAttributes();
		}

	}

}
