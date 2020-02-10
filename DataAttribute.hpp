#ifndef DATAATTRIBUTE_HPP
#define DATAATTRIBUTE_HPP 1

#include <boost/optional.hpp>
#include <QVariant>
#include <unordered_set>

namespace UPIM{
	namespace DATA{

		class DataAttribute{
		public:
			DataAttribute() noexcept;

            DataAttribute(const QString& name, const QString& owner, const QVariant& value, const QString& semantic = "") noexcept;

            DataAttribute(QString&& name, QString&& owner,QVariant&& value,QString&& semantic = "") noexcept;

            QString GetName() const noexcept;

            QString GetOwner() const noexcept;

            QVariant GetValue() const noexcept;

            QVariant& GetValue() noexcept;

            QString GetSemantic() const noexcept;

		private:
            QString _name = "";
            QString _owner = "";
            boost::optional<QVariant> _value;
            QString _semantic = "";
		};

		bool operator==(const DataAttribute& lhs, const DataAttribute&rhs);

		struct DataAttributeHash{
			size_t operator()(const DataAttribute& _attr) const;
		};

        //std::string to_str(const QString& wstr) noexcept;

}
}

#endif
