#pragma once

enum class errorTypes {
	DEFAULT,
	DEBUG, //intentionally throw one for debugging purposes
	HTTP,
	FATAL,
	MISSING_ENUM,
	UNEXPECTED_TYPE,
};