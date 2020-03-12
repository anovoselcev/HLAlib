#include "DataAttribute.hpp"

namespace UPIM{
	namespace DATA{
		using namespace std;

		DataAttribute::DataAttribute() noexcept{}

        DataAttribute::DataAttribute(const QString& name, const QString& owner, const QVariant& value, const QString& semantic) noexcept:
					_name(name), _owner(owner), _value(value), _semantic(semantic){}

        DataAttribute::DataAttribute(QString&& name, QString&& owner,QVariant&& value,QString&& semantic) noexcept:
                    _name(std::move(name)), _owner(std::move(owner)), _value(std::move(value)), _semantic(std::move(semantic)) {}

        QString DataAttribute::GetName() const noexcept{return _name;}

        QString DataAttribute::GetOwner() const noexcept{return _owner;}

        QVariant DataAttribute::GetValue() const noexcept{return _value;}

        QVariant& DataAttribute::GetValue() noexcept {return _value;}

        QString DataAttribute::GetSemantic() const noexcept{return _semantic;}

        bool DataAttribute::operator==(const DataAttribute &other) const noexcept{
            return other.GetName() == _name && other.GetOwner() == _owner && other.GetSemantic() == _semantic && other.GetValue() == _value;
        }

        bool DataAttribute::operator<(const DataAttribute &other) const noexcept{
            return _value < other.GetValue() && _name < other.GetName() && _owner < other.GetOwner() && _semantic < other.GetSemantic();
        }

        size_t DataAttributeHash::operator ()(const DataAttribute& attr) const{
            size_t h1 = qHash(attr.GetName());
            size_t h2 = qHash(attr.GetOwner());
            size_t h3 = qHash(attr.GetValue().toByteArray());
            size_t h4 = qHash(attr.GetSemantic());
            return h4+h3*199+h2*199*199+h1*199*199*199;
		}

        size_t QStringHash::operator()(const QString& _str) const{
            return qHash(_str);
        }

	}
}
