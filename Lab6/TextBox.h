#pragma once

__interface TextBox
{
public:
	virtual void setText(std::string& text) ;
	virtual const std::string& getText() const ; 
	virtual void onValueChanged();
};
