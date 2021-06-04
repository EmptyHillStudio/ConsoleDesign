#pragma once
enum class LineState
{
	CLOSED,//关闭状态
	OPENED,//开放状态
	LOCKED,//冻结状态（如果产生异常，比如飞机老化、占有率到达0%等，将会触发这一状态）
};

