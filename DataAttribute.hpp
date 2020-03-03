#ifndef DATAATTRIBUTE_HPP
#define DATAATTRIBUTE_HPP 1

#include <QVariant>

namespace UPIM{
	namespace DATA{
//Data structure for ordinary Attribute
		class DataAttribute{

        public:
//Default constructor
            DataAttribute() noexcept;

//Full-gapes lvalue constructor
            DataAttribute(const QString& name, const QString& owner, const QVariant& value, const QString& semantic = "") noexcept;

//Full-gapes rvalue constructor
            DataAttribute(QString&& name, QString&& owner,QVariant&& value,QString&& semantic = "") noexcept;

//Copy constructor
            DataAttribute(const DataAttribute&) = default;

//Move constructor
            DataAttribute(DataAttribute&&) = default;

//Copy assigment operator
            DataAttribute& operator=(const DataAttribute&) = default;

//Move assigment operator
            DataAttribute& operator=(DataAttribute&&) = default;

//Get attribute name
            QString GetName() const noexcept;

//Get name of the attribute owner
            QString GetOwner() const noexcept;

//Get attribute value(const)
            QVariant GetValue() const noexcept;

//Get attribute value to change
            QVariant& GetValue() noexcept;

   //Get other info about attribute
            QString GetSemantic() const noexcept;

            bool operator==(const DataAttribute& other) const noexcept;

            bool operator<(const DataAttribute& other) const noexcept;

		private:

//Attribute name
            QString _name = "";
//Owner name
            QString _owner = "";
//Attribute value
            QVariant _value;
//Other info about attribute
            QString _semantic = "";
		};



//Hasher for Attribute
		struct DataAttributeHash{
            size_t operator()(const DataAttribute& _attr) const;
		};
//Hasher for QString
        struct QStringHash{
            size_t operator()(const QString& _str) const;
        };
}
}

#endif
